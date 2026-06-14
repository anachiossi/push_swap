# ps_gen

Interactive push swap input generator. Produces a ready-to-run `./push_swap` command with a random array of valid intergers, at requested size and disorder level.

## Build

```
cd tools/ps_gen && make
```

## Usage

Run from the repo root:

```
tools/ps_gen/ps_gen
```

Or from inside `tools/ps_gen/`:

```
./ps_gen
```

The program asks four questions interactively:

| Prompt | Values | Effect |
|---|---|---|
| How many numbers? | 1 – 1000 | size of the input array |
| How much disorder? | 0.0 – 1.0 | 0.0 = sorted, 1.0 = fully reversed |
| Which algorithm? | adaptive / simple / medium / complex | sets the `--flag` passed to push_swap |
| Do you need benchmarks? | y / n | prints size and disorder stats before the command |

## Output

```
size               : 5
disorder target    : 0.8000
disorder generated : 0.8000
./push_swap --adaptive 3 5 1 4 2
```

Copy the last line of the output and run it manually:

```
./push_swap 3 5 1 4 2
```

To count the number of operations:

```
./push_swap 3 5 1 4 2 | wc -l
```

## Notes

- Disorder is approximate — the generator targets the requested value but the actual value may differ slightly for small arrays.
