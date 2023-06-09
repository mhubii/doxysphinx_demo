# Doxysphinx Demo
[Doxysphinx](https://boschglobal.github.io/doxysphinx/) converts [Doxygen](https://www.doxygen.nl/) to [Sphinx](https://www.sphinx-doc.org/en/master/). This repository demonstrates how to use [Doxysphinx](https://boschglobal.github.io/doxysphinx/) and how to host it on [Read the Docs](https://readthedocs.org/).

[![Documentation Status](https://readthedocs.org/projects/doxysphinx-demo/badge/?version=latest)](https://doxysphinx-demo.readthedocs.io/en/latest/?badge=latest)

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
git submodule add -b main https://github.com/mhubii/geometry_lib
git submodule add -b main https://github.com/jothepro/doxygen-awesome-css
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

- Modify the `Doxyfile`. Change
```
PROJECT_NAME           = "Geometry Lib"
OUTPUT_DIRECTORY       = "docs/doxygen/geometry_lib"
SHOW_FILES             = NO # redundant to show files when we document already
INPUT                  = "../../geometry_lib" # the library we added as submodule
RECURSIVE              = YES
VERBATIM_HEADERS       = NO # redundant to show files when we document already
HTML_EXTRA_STYLESHEET = "../../doxygen-awesome-css/doxygen-awesome.css" # requires doxygen-awesome, added as a submodule
SEARCHENGINE           = NO # sphinx has a search engine already
GENERATE_LATEX         = NO
GENERATE_XML           = YES
GENERATE_TAGFILE       = "docs/doxygen/geometry_lib/html/tagfile.xml"
DOT_IMAGE_FORMAT       = svg # requires graphviz, to be installed via .readthedocs.yaml
INTERACTIVE_SVG        = YES
DOT_TRANSPARENT        = YES
```

Also refer to `Doxysphinx` [mandatory settings](https://boschglobal.github.io/doxysphinx/docs/getting_started.html#mandatory-settings) and [recommended settings](https://boschglobal.github.io/doxysphinx/docs/getting_started.html#recommended-settings).


- Add `Doxygen` and `Doxysphinx` to build. To [conf.py](doc/source/conf.py) add
```python
import pathlib
import subprocess

# generate doxygen
pathlib.Path("docs/doxygen/geometry_lib").mkdir(parents=True) # this is the doxygen OUTPUT_DIRECTORY
subprocess.run("doxygen", shell=True)

# convert doxygen to sphinx, source and build directory need
# to follow https://boschglobal.github.io/doxysphinx/docs/getting_started.html#build
subprocess.run("doxysphinx build . $READTHEDOCS_OUTPUT/html Doxyfile", shell=True)
```

Change theme in [conf.py](doc/source/conf.py) to
```python
html_theme = "sphinx_rtd_theme"
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
   docs/doxygen/geometry_lib/html/index
```

- Done! This repository can now be hosted on [Read the Docs](https://doxysphinx-demo.readthedocs.io/en/latest/?badge=latest).

## Auto Update Submodules
To auto-update the submodules, add a workflow, see [update_submodules.yml](.github/workflows/update_submodules.yml).
