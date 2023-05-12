# Diddy Kong Racing

A repository exploring a decompilation of alternative versions of Diddy Kong Racing

This is just to run splat on versions of Diddy Kong Racing other than US v1.0. This will never be a main repository for decomp.

Grab tools

```sh
git submodule update --init --recursive
```

Install Dependencies
```sh
sudo apt install build-essential pkg-config git python3 wget libcapstone-dev python3-pip binutils-mips-linux-gnu
python3 -m pip install --user colorama watchdog levenshtein cxxfilt
python3 -m pip install --upgrade pycparser
```

```sh
make dependencies
make extract
make
```

