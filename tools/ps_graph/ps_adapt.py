import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches

df = pd.read_csv('ps_graph_data.txt', sep='\t')

sizes    = sorted(df['size'].unique())
disorders = sorted(df['disorder'].unique())

simple_  = df[df['algorithm'] == 'simple'].set_index(['size', 'disorder'])['ops_avg']
complex_ = df[df['algorithm'] == 'complex'].set_index(['size', 'disorder'])['ops_avg']
diff     = simple_ - complex_   # negative = simple wins, positive = complex wins

def crossovers(n):
    pts = []
    prev_winner = None
    for i in range(len(disorders) - 1):
        d1, d2 = disorders[i], disorders[i + 1]
        try:
            v1, v2 = diff[(n, d1)], diff[(n, d2)]
        except KeyError:
            continue
        if v1 * v2 < 0:
            cx = d1 - v1 * (d2 - d1) / (v2 - v1)
            pts.append(cx)
    return pts

# --- size crossover at d=0.5 ---
n_cross = None
for i in range(len(sizes) - 1):
    n1, n2 = sizes[i], sizes[i + 1]
    try:
        v1, v2 = diff[(n1, 0.5)], diff[(n2, 0.5)]
        if v1 * v2 < 0:
            n_cross = n1 - v1 * (n2 - n1) / (v2 - v1)
            break
    except KeyError:
        pass

# --- disorder crossovers per size ---
d_low_pts  = []   # (n, d) where simple → complex
d_high_pts = []   # (n, d) where complex → simple

for n in sizes:
    cx = crossovers(n)
    if len(cx) >= 2:
        lo, hi = sorted(cx)[:2]
        d_low_pts.append((n, lo))
        d_high_pts.append((n, hi))
    elif len(cx) == 1:
        try:
            first = diff[(n, disorders[0])]
            if first < 0:
                d_low_pts.append((n, cx[0]))
            else:
                d_high_pts.append((n, cx[0]))
        except KeyError:
            pass

# --- print report ---
print()
print("  ps_adapt  |  empirical algorithm selection zones")
print("  " + "=" * 50)

if n_cross:
    print(f"\n  size crossover (d=0.5):  n ≈ {n_cross:.0f}")
    print(f"    → below n≈{n_cross:.0f} : simple wins regardless of disorder")

print(f"\n  disorder crossovers per size (where simple ↔ complex):")
print(f"  {'n':>6}  {'simple wins when':>35}")
print("  " + "-" * 44)

for n in sizes:
    cx = crossovers(n)
    try:
        first = diff[(n, disorders[0])]
    except KeyError:
        continue

    if not cx:
        zone = 'always' if first <= 0 else 'never'
        print(f"  {n:>6}  {zone:>35}")
    elif len(cx) == 1:
        c = cx[0]
        zone = f'd < {c:.2f}' if first < 0 else f'd > {c:.2f}'
        print(f"  {n:>6}  {zone:>35}")
    else:
        lo, hi = sorted(cx)[:2]
        if first < 0:
            zone = f'd < {lo:.2f}  or  d > {hi:.2f}'
        else:
            zone = f'{lo:.2f} < d < {hi:.2f}'
        print(f"  {n:>6}  {zone:>35}")

# --- adaptive rules summary ---
if d_low_pts and d_high_pts and n_cross:
    lo_ns, lo_ds = zip(*d_low_pts)
    hi_ns, hi_ds = zip(*d_high_pts)
    avg_lo = np.mean(lo_ds)
    avg_hi = np.mean(hi_ds)
    print(f"\n  adaptive rule (simplified average thresholds):")
    print(f"    if n < {n_cross:.0f}:")
    print(f"      → use simple")
    print(f"    else:")
    print(f"      if d < {avg_lo:.2f} or d > {avg_hi:.2f}:")
    print(f"        → use simple")
    print(f"      else:")
    print(f"        → use complex")

print()

# --- heatmap ---
grid = np.full((len(sizes), len(disorders)), np.nan)
for i, n in enumerate(sizes):
    for j, d in enumerate(disorders):
        try:
            grid[i, j] = 0 if diff[(n, d)] <= 0 else 1
        except KeyError:
            pass

fig, ax = plt.subplots(figsize=(10, 6))
cmap = plt.cm.colors.ListedColormap(['#4fc3f7', '#ffb74d'])
ax.imshow(grid, aspect='auto', origin='lower', cmap=cmap, vmin=0, vmax=1)

ax.set_xticks(range(len(disorders)))
ax.set_xticklabels([f'{d:.2f}' for d in disorders], rotation=45, ha='right', fontsize=7)
ax.set_yticks(range(len(sizes)))
ax.set_yticklabels(sizes, fontsize=7)
ax.set_xlabel('disorder')
ax.set_ylabel('size')
ax.set_title('best algorithm per (size, disorder)\n[blue = simple, orange = complex]')

simple_patch  = mpatches.Patch(color='#4fc3f7', label='simple')
complex_patch = mpatches.Patch(color='#ffb74d', label='complex')
ax.legend(handles=[simple_patch, complex_patch], loc='upper left')

if n_cross:
    n_idx = np.interp(n_cross, sizes, range(len(sizes)))
    ax.axhline(n_idx, color='white', linestyle='--', linewidth=1.2)
    ax.text(len(disorders) - 1, n_idx + 0.2, f'n≈{n_cross:.0f}', color='white', fontsize=8, ha='right')

plt.tight_layout()
plt.savefig('ps_adapt.png', dpi=150)
plt.show()
