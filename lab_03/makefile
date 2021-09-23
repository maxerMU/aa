CC=gcc
LINTER=cppcheck

INCPATH=./inc/
OUTPATH=./out/
SRCPATH=./src/

INC=-I$(INCPATH)
CFLAGS=-std=c99 -Wall -Werror -Wpedantic --coverage -Wfloat-equal -Wvla -g3 -ggdb
LFLAGS=--coverage
CHECKFLAGS=-lcheck

OBJFILES=$(OUTPATH)main.o $(OUTPATH)gen.o $(OUTPATH)sorts.o $(OUTPATH)statistic.o

WINDOWS=WINDOWS_NT

.PHONY: clean release debug func unit
.NOTPARALLEL: release debug func

ifneq ($(OS),$(WINDOWS))
	CHECKFLAGS+=-lpthread -lrt
endif

release: CFLAGS=-std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wvla -o3
release: LFLAGS=-o3
release: $(OUTPATH)release.lastbuildstate app.exe

debug: $(OUTPATH)debug.lastbuildstate app.exe

$(OUTPATH)release.lastbuildstate: | $(OUTPATH)
	rm -rf $(OUTPATH)*.o $(OUTPATH)*.gcno $(OUTPATH)*.gcov $(OUTPATH)*.gcda $(OUTPATH)*.lastbuildstate *.exe
	touch $(OUTPATH)release.lastbuildstate

$(OUTPATH)debug.lastbuildstate: | $(OUTPATH)
	rm -rf $(OUTPATH)*.o $(OUTPATH)*.gcno $(OUTPATH)*.gcov $(OUTPATH)*.gcda $(OUTPATH)*.lastbuildstate *.exe
	touch $(OUTPATH)debug.lastbuildstate

app.exe: $(OBJFILES)
	$(CC) $(LFLAGS) -o $@ $^ -lm

$(OUTPATH)main.o: $(SRCPATH)main.c | $(OUTPATH)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OUTPATH)gen.o: $(SRCPATH)gen.c $(INCPATH)gen.h | $(OUTPATH)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OUTPATH)sorts.o: $(SRCPATH)sorts.c $(INCPATH)sorts.h | $(OUTPATH)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OUTPATH)statistic.o: $(SRCPATH)statistic.c $(INCPATH)statistic.h | $(OUTPATH)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OUTPATH):
	mkdir $(OUTPATH)

clean:
	rm -rf $(OUTPATH)*.o $(OUTPATH)*.gcno $(OUTPATH)*.gcov $(OUTPATH)*.gcda $(OUTPATH)*.lastbuildstate *.exe
