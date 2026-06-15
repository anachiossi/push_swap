# ps_graph

Empirical sweep tool for push_swap. Runs push_swap across every combination of size, disorder level, and algorithm, averages results over multiple random samples, and writes a tab-separated data file that the Python scripts turn into graphs.

## Build

```
cd tools/ps_graph
make
```

The Makefile substitutes the absolute paths to `push_swap` and `ps_gen` into the script at build time. Paths are resolved relative to the Makefile location with `$(abspath ...)` — no hardcoded usernames, works on any machine as long as the folder structure is the same.

## Run

```
./ps_graph              # writes to ps_graph_data.txt
./ps_graph my_data.txt  # writes to a custom file
```

Progress is printed to stdout. Total time depends on the parameter grid — with the default settings and two algorithms, expect around 10–15 minutes.

## Parameters

All tunable parameters live at the top of `ps_graph.tpl`. Edit them there, then run `make re` to regenerate the script.

### SIZES

```bash
SIZES=(1 5 10 20 35 50 65 80 100 150 200 300 500 750 1000)
```

Array sizes to test. These become the x-axis of the ops vs size graph. The current set is denser at small sizes where algorithm behaviour changes fastest, and sparser toward the top. Adding large values like 5000 or 10000 is possible but `simple` becomes impractically slow there (selection sort is O(n²)).

### DISORDERS

```bash
DISORDERS=(0 0.05 0.1 0.15 0.2 0.25 0.3 0.35 0.4 0.45 0.5 0.55 0.6 0.65 0.7 0.75 0.8 0.85 0.9 0.95 1.0)
```

Disorder levels from 0.0 (perfectly sorted) to 1.0 (fully reversed), in steps of 0.05. These become the x-axis of the disorder graphs. Finer steps give smoother curves but multiply sweep time proportionally.

### ALGORITHMS

```bash
ALGORITHMS=("simple:1" "medium:2" "complex:3")
# add "adaptive:0" when implemented — appears in runtime graph only
```

Each entry is `name:level`. The name becomes the `--flag` passed to push_swap and the label in the data file. The level number is passed to ps_gen so it generates an input matched to that algorithm's expected input style.

To add adaptive when it is ready: uncomment `"adaptive:0"` in the tpl and rebuild. The Python scripts automatically exclude adaptive from the ops graphs (`ops_df` filter) and include it only in the runtime and challenge-target graphs.

### RUNS

```bash
RUNS=5
```

How many independent random samples to generate and average per (size, disorder, algorithm) point.

**Why not just run once?**

For a fixed size and disorder level, ps_gen generates a *different* random array on every call. The number of operations is not a fixed function of those two parameters alone — it also depends on *where* in the stack the disorder is concentrated.

Selection sort is the clearest example: if the minimum element is near the top of the stack it costs almost nothing to bring it to position. If it is near the bottom it requires rotating through the entire stack first. A single sample can hit either extreme by chance, producing a datapoint that looks like an outlier but is not — it is just one specific arrangement. With 5 runs, each point is the mean of 5 independent draws from the space of arrays with that (size, disorder) pair, which smooths out that positional variance and makes the curves stable across different sweeps.

Raising `RUNS` reduces noise further at the cost of proportionally more time. Lowering it speeds up the sweep but makes disorder curves jagged, especially for small n where the number of distinct arrangements is limited.

## Output format

Tab-separated, one line per (size, disorder, algorithm) point:

```
size    disorder    algorithm    ops_avg    time_ms_avg
10      0.5         simple       42         1
10      0.5         complex      38         0
```

`ops_avg` and `time_ms_avg` are integer means over `RUNS` samples. Time is measured with `date +%s%N` (nanosecond precision, Linux / GNU coreutils only) and converted to milliseconds. Only the push_swap execution is timed — the ps_gen call is excluded.

## Python scripts

All three scripts read `ps_graph_data.txt` from the working directory. Run them from the ps_graph folder after a sweep.

### ps_plot.py

```
python3 ps_plot.py
```

Produces `ps_plot.png` — a 5×2 grid of graphs:

| Position | Graph |
|---|---|
| top left | ops vs size (disorder = 0.5) |
| top right | ops vs disorder (n = 10) |
| row 2 left | ops vs disorder (n = 100) |
| row 2 right | ops vs disorder (n = 500) |
| row 3 left | challenge targets n = 100 — pass < 2000, good < 1500, excellent < 700 |
| row 3 right | challenge targets n = 500 — pass < 12000, good < 8000, excellent < 5500 |
| row 4 left | challenge targets n = 50 (extrapolated from power law) |
| row 4 right | challenge targets n = 10 (extrapolated from power law) |
| row 5 left | runtime vs size (disorder = 0.5) |

Adaptive is excluded from all ops graphs even if present in the data; it shows in the runtime and challenge-target graphs. Crossover points (where simple and complex switch efficiency) are detected by sign-change interpolation and annotated automatically.

### ps_bigo.py

```
python3 ps_bigo.py
```

Fits a power law `ops = a * n^k` to the data at disorder = 0.5 for sizes ≥ 20, using log-log linear regression. Produces `ps_bigo.png` and `ps_bigo.txt`.

The plot uses a log-log scale because any power law `ops = a * n^k` becomes a straight line on it:

```
log(ops) = k * log(n) + log(a)
```

The slope of the line is the exponent `k`, so you can read the Big O directly from the steepness. The dots are the real measurements from the sweep; the dashed line is the fitted `a * n^k`. If the dots follow the line tightly, R² is close to 1.0 and the algorithm genuinely behaves like that complexity class.

All algorithms present in the data are plotted automatically — no code change needed when medium is added.

### ps_adapt.py

```
python3 ps_adapt.py
```

Investigation tool that finds the crossover regions where simple outperforms complex across the full (n, disorder) plane. Produces a heatmap and derives a concrete adaptive decision rule: which algorithm to use given input size and disorder. Intentionally hardcoded to simple vs complex — this is the analysis that informs the adaptive algorithm design, not a general comparison tool.

## How the template system works

`ps_graph` is not stored directly. `ps_graph.tpl` is the source of truth, with two placeholder tokens:

- `__PUSH_SWAP__` — replaced with the absolute path to the push_swap binary
- `__PS_GEN__` — replaced with the absolute path to the ps_gen binary

Running `make` passes `ps_graph.tpl` through `sed` with both substitutions and writes the result to `ps_graph`, then marks it executable. This means the paths are baked in at build time and the script works correctly from any working directory, without requiring the user to set environment variables or edit paths by hand.
