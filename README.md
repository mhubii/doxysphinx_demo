# Doxysphinx Demo

# Install Dependencies


# Sphinx-Quickstart
sphinx-quickstart

Separate source and build directories (y/n) [n]: y
Project name: Human
Author name(s): mhubii
Project release []: 1.0.0
Project language [en]: en

# Doxygen
doxygen -g

INPUT                  = "../humanlib"

[Mandatory settings](https://boschglobal.github.io/doxysphinx/docs/getting_started.html#mandatory-settings)

Additional configs

PROJECT_NAME           = "Human"
RECURSIVE              = YES
GENERATE_LATEX         = NO
GENERATE_XML           = YES
SHOW_FILES             = NO
VERBATIM_HEADERS       = NO

[See notes](https://boschglobal.github.io/doxysphinx/docs/getting_started.html#mandatory-settings)
OUTPUT_DIRECTORY       = "source/docs/doxygen"
mkdir -p source/docs/doxygen

CSS style https://github.com/jothepro/doxygen-awesome-css.git
HTML_EXTRA_STYLESHEET = YOUR_DOXYGEN_AWESOME_PATH/doxygen-awesome.css


<!-- [Recommended settings](https://boschglobal.github.io/doxysphinx/docs/getting_started.html#recommended-settings) -->

doxygen

# Doxysphinx
to source/index.rst add

API
===
.. toctree::
   docs/doxygen/html/index

doxysphinx build source/ build/ Doxyfile
sphinx-build -b html source/ build/

Open build/index.html