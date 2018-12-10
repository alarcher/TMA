TEXFILES=$(wildcard L*.tex)
PDFFILES=$(patsubst %.tex, %.pdf, $(TEXFILES))

%.pdf : %.tex
	pdflatex -halt-on-error -interaction=nonstopmode $<

all: $(PDFFILES)
