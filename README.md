# Diddy Kong Racing

A repository exploring a decompilation of alternative versions of Diddy Kong Racing

This is just to run splat on versions of Diddy Kong Racing other than US v1.0. This will never be a main repository for decomp.

Put all baseroms into the baseroms folder as the first step. They will automatically be detected and renamed from there.

Grab tools

```sh
git submodule update --init --recursive
```

Install Dependencies
```sh
sudo apt install build-essential pkg-config git python3 wget python3-pip binutils-mips-linux-gnu python3-venv
```

```sh
make dependencies
make extract
make
```

```
As of 2025-02-25

JPN Match:
1803 matched functions / 1939 total (92.99%)
606588 matching bytes / 866924 total (69.97%)

US V77 Match:
1795 matched functions / 1928 total (93.10%)
606792 matching bytes / 860372 total (70.53%)
```
