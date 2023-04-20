import pathlib
import subprocess

# generate doxygen
pathlib.Path("docs/doxygen/geometry_lib").mkdir(parents=True)
subprocess.run("doxygen", shell=True)

# convert doxygen to sphinx
subprocess.run("doxysphinx build . $READTHEDOCS_OUTPUT/html Doxyfile", shell=True)

# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = "Geometry Lib"
copyright = "2023, your_name"
author = "your_name"
release = "1.0.0"

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = []

templates_path = ["_templates"]
exclude_patterns = []


# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = "sphinx_rtd_theme"
html_static_path = ["_static"]
