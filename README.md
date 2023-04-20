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
mkdir doc && cd doc
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

- Generate a default `Doxyfile`
```shell
cd source
doxygen -g
```

- Modify the `Doxyfile`
Also refer to `Doxysphinx` [mandatory settings](https://boschglobal.github.io/doxysphinx/docs/getting_started.html#mandatory-settings) and [recommended settings](https://boschglobal.github.io/doxysphinx/docs/getting_started.html#recommended-settings).

Additionally change
```
INPUT                  = "../../geometry_lib"
PROJECT_NAME           = "Geometry Lib"
RECURSIVE              = YES
GENERATE_LATEX         = NO
GENERATE_XML           = YES
SHOW_FILES             = NO
VERBATIM_HEADERS       = NO
OUTPUT_DIRECTORY       = "docs/doxygen/geometry_lib"
SEARCHENGINE           = NO
DOT_IMAGE_FORMAT       = svg
INTERACTIVE_SVG        = YES
DOT_TRANSPARENT        = YES
GENERATE_TAGFILE       = "docs/doxygen/geometry_lib/html/tagfile.xml"
HTML_EXTRA_STYLESHEET = "../../doxygen-awesome-css/doxygen-awesome.css"
```

- Add `Doxygen` and `Doxysphinx` to build
To [conf.py](doc/source/conf.py) add
```python
import subprocess

# generate doxygen
subprocess.run("doxygen", shell=True)

# convert doxygen to sphinx
subprocess.run("doxysphinx build . $READTHEDOCS_OUTPUT/html Doxyfile", shell=True)
```

- Add [.readthedocs.yaml](.readthedocs.yaml)
   - Include submodules
   - Install `graphviz`
   - Add [requirements.txt](requirements.txt) to install `doxysphinx`

- Link to the generated documentation (see [documentation](https://boschglobal.github.io/doxysphinx/docs/linking_to_doxygen.html))
E.g., to [index.rst](doc/source/index.rst) add

```
API
===
.. toctree::
   docs/doxygen/html/index
```
