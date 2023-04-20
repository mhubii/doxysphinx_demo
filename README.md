# Doxysphinx Demo
[Doxysphinx](https://boschglobal.github.io/doxysphinx/) converts [Doxygen](https://www.doxygen.nl/) to [Sphinx](https://www.sphinx-doc.org/en/master/). This repository demonstrates how to use [Doxysphinx](https://boschglobal.github.io/doxysphinx/) and how to host it on [Read the Docs](https://readthedocs.org/).

## Goal
Generate documentation for a C++ library from docstrings and host it on [Read the Docs](https://readthedocs.org/).

Consider a dummy library [geometry_lib](https://github.com/mhubii/geometry_lib) for this purpose.

## Step by Step
Following the steps will re-create this repository!

- Create a folder
```shell
mkdir doxysphinx_demo
cd doxysphinx_demo
git init
```

- Add 2 submodules
   - The library you plan to document
   - A modern style sheet for Doxygen, [Doxygen Awesome](https://jothepro.github.io/doxygen-awesome-css/)

```shell
git submodule add https://github.com/mhubii/geometry_lib
git submodule add https://github.com/jothepro/doxygen-awesome-css
```

- Initialize `Sphinx`
```shell
sphinx-quickstart
```

Answer similar to

```shell
Separate source and build directories (y/n) [n]: y
Project name: Geometry Lib
Author name(s): your_name
Project release []: 1.0.0
Project language [en]: en
```

- Generate a `Doxyfile`

