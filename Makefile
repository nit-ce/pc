# Neatroff setup
BASE = $(PWD)/neatroff_make/
ROFF = $(BASE)/neatroff/roff
POST = $(BASE)/neatpost/post
EQN = $(BASE)/neateqn/eqn
REFER = $(BASE)/neatrefer/refer
PIC = $(BASE)/troff/pic/pic
TBL = $(BASE)/troff/tbl/tbl
SOIN = $(BASE)/soin/soin
SHAPE = $(BASE)/shape/shape

# Compiler setup
CC = cc
CFLAGS = -Wall -O2
LDFLAGS =

all: pc00.pdf pc01.pdf pc02.pdf pc03.pdf pc04.pdf \
	g01 g02 g03 g04 \
	v01 v02 v03 v04

help:
	@echo "Wednesday Programming Problem top-level Makefile"
	@echo
	@echo "   init        Obtain Neatroff and its fonts and build them"
	@echo "   all         Build the programs and problem statements"
	@echo "   clean       Remove the generated files"
	@echo

init:
	@git clone git://github.com/litcave/neatroff_make.git
	@cd neatroff_make/ && make init_fa
	@cd neatroff_make/ && make neat

%.o: %.c
	$(CC) -c $(CFLAGS) $<
g%: g%.o
	$(CC) -o $@ $^ $(LDFLAGS)
v%: v%.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.ps: %.tr
	@echo "Generating $@"
	@cat $< | $(SHAPE) | $(PIC) | $(TBL) | $(EQN) | $(ROFF) | $(POST) -pa4 >$@

%.ps: %.ms
	@echo "Generating $@"
	@cat $< | $(SOIN) | $(SHAPE) | \
		$(REFER) -m -e -o ct -p ref.bib | $(PIC) | $(TBL) | $(EQN) | \
		$(ROFF) -meps -mtbl -mkeep -mfa -msrefs | $(POST) -pa4 | \
		sed "/^%%Creator:/a%%Title: `sed -n 's/^.*PSTITLE: \(.*\)/\1/p' <$<`" >$@

%.pdf: %.ps
	@echo "Generating $@"
	@ps2pdf -dPDFSETTINGS=/prepress -dEmbedAllFonts=true -sFONTPATH=$(BASE)/fonts/ $< $@

clean:
	rm -f *.ps *.pdf v?? g?? *.o
