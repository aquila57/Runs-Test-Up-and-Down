# Test for Runs Up and Down

Test for Runs Up and Down is a two phase test for random
number generators.  The first phase calculates a Z-score
based on runs up and down.  The second phase calculates a
chi square test based on the length of all runs, both up
and down.

See the repository "Test for Runs Above and Below the Mean"
for information about that type of runs test.

The tests in this repository are applied against a variety
of random number generators, some weak and some strong.
The purpose of this repository is to show how the runs
test is performed, and what types of generators pass or
fail the test.

The inspiration for this repository is an online document
at Bucknell University by Professor Xiannong Meng.
Professor Meng has not updated his document since October
of 2002.  The programs in this repository illustrate how
the runs test is performed using the C language.

https://www.eg.bucknell.edu/~xmeng/Course/CS6337/Note/master/node44.html

Thanks to Dr. Meng for pointing us in the right direction for
this test.

The nomenclature that I use in the programs follows his
notation as much as possible.  Dr. Meng uses the subscript
alpha for variables used in the runs up and down test.

Example of ten samples.

The following is a list of ten samples.

	0.01
	0.14
	0.43
	0.76
	0.67
	0.71
	0.66
	0.88
	0.90
	0.40

The first  run is a run up   of length 3.
The second run is a run down of length 1.
The third  run is a run up   of length 1.
The fourth run is a run down of length 1.
The fifth  run is a run up   of length 2.
The sixth  run is a run down of length 1.

In this example there are

	4 runs of length 1
	1 run  of length 2
	1 run  of length 3

In a large test of ten million samples, the total number
of runs follows a normal distribution.  The length of
runs follows a chi square distribution.

Random number generators used in this test.

eegl64

The eegl64 random number generator is explained in the repository
"eegl64".  That is a random number generator based on a 64 bit
LFSR with a Bays Durham shuffle.  The period length of the eegl64
generator approximates 1.2 * 10^61036 generations.  That is a long
period length, that never terminates, or wraps around.  The eegl64
generator passes the runs up and down test.

----------------

etaus

The eetaus random number generator is explained in the repository
"etaus".  That is a random number generator based on the Tausworthe
algorithm by Pierre L'Ecuyer at the University of Montreal.
Etaus uses the Bays-Durham shuffle.  The period length of this
generator approximates 1.2 * 10^61036 generations.  That is a
long period length, that never terminates, or wraps around.  The
etaus generator passes the runs up and down test.

----------------

Fibonacci

The fibonacci random number generator illustrates how a weak
random number generator fails both phases of the runs up and
down test.

The fibonacci generator is computed in the gen_dbl() function
in the runsfibo.c program.

fibonum1 = fibonum2
fibonum2 = fibonum3
fibonum3 = fibonum1 + fibonum2
fraction = fibonum3 / maxint

fraction is a pseudo random number with a uniform distribution
ranging from zero to one.

----------------

LFSR

The LFSR random number generator illustrates how a weak
random number generator fails both phases of the runs up
and down test.

The LFSR generator is computed in the gen_dbl() function in the
runslfsr.c program.  See the macro MYLFSR at the beginning of
the program for the algorithm used in the LFSR generator.  The
LFSR generator used is a 64 bit linear feedback shift register
with a period length of 2^64.

MYLFSR;
fraction = lfsr / maxint

fraction is a pseudo random number with a uniform distribution
ranging from zero to one.

----------------

RANDU

The RANDU random number generator illustrates how a weak
random number generator is able to pass Z-score part of
the runs up and down test and fail the chi square test.

The RANDU generator is computed in the gen_dbl() function
in the ruruns.c program.  RANDU is a 32 bit generator with
a period length of 2^30.

seed *= 65539;
fraction = seed / maxint

fraction is a pseudo random number with a uniform distribution
ranging from zero to one.

----------------

Sine Wave Generator

The sine random number generator illustrates how a weak
random number generator is able to pass the runs up and down
test.

The sine generator is computed in the gen_dbl() function
in the runsine.c program.  The sine generator has a long
enough period length to complete the test.

/* generate a uniform number between zero and PI */
radian = eeglunif(ee) * M_PI;
sinx = sin(radian);

sinx is a pseudo random number with a sine distribution
ranging from zero to one.

----------------

GNU Scientific Library Generators

The GSL generators illustrate how a variety of strong random
number generators perform well in the runs up and down test.

The GSL generators are computed in the gen_dbl() function
in the runsgsl.c program.  The GSL generators have a long
enough period length to complete the test.

fraction = gsl_rng_uniform(rng);

fraction is a strong random number with a uniform distribution
ranging from zero to one.

The following GSL generators fail the runs up and down test.
These same generators also fail the runs test above and below
the mean.  Randu is a weak generator and is expected to fail
the test.  However the random32 group of generators is puzzling,
because other groups of random??? generators pass the test.  For
example, the random256 group passes the test.

random32-bsd

random32-glibc2

random32-libc5

randu

----------------

Dieharder generators

The dieharder package contains 74 well known random number
generators.  Dieharder can generate 32 bit unsigned integers
from these generators with the following command.

dieharder -g nnn -t yyy -o

where nnn is the three digit number of the generator, and
yyy is the number of integers to generate.

For example,

dieharder -g 053 -t 1000 -o

This example generates one thousand 32 bit integers using
the taus2 generator.  053 is the number of the taus2 generator.

To see all the generator numbers, run the following command.

dieharder -g -l

The runs up and down command for dieharder generators in this
repository is called tstdie.sh.  The parameter for this command
is the dieharder generator number.  For example,

tstdie.sh 053

This runs the test using the taus2 generator from dieharder.

-----------------------------------------------------------

The following are the subroutines used in the runs up and
down test.

add_both_tallies.c - add the runs up and runs down totals together

bld_curr_smpl.c - create the current sample and calculate whether
it starts a new run.  If not, add to the length of the current
run.

bld_frst_run.c - Like the current sample, only this calculates
whether the first run is up or down.

bld_maxint.c - for dieharder generators, build a table of maximum
integers unique to each generator.

bld_rngtbl.c - for dieharder, maintain a table of generator names
associated with each generator number.

bldsmpls.c - create one million samples to calculate number of
runs up and down, and to calculate the length of each run.

calcchi_up.c - calculate the chi square test based on total
run lengths.

calc_exp_up.c - calculate expected run statistics.

calc_zedzero.c - calculate Z score based on number of runs.

Eegl64 subroutines.

eeglabt.c - print copyright and a summary of the GNU Public License.

eeglbit.c - output a random bit

eegl.c - core randomizer, outputs a 32 bit unsigned integer.

eeglcrc.c - calculate the crc for the initial seed.

eegldspl.c - display the internal state of the generator.

eeglfrac.c - generate a 53 bit fraction between zero and one.

eeglinit.c - initialize the generator based on date, time, and
number of ticks since the machine was booted.

eeglint.c - generate a random integer between zero and a limit
minus one.

eeglpwr.c - generate from 1 to 32 random bits.

eeglsd.c - generate a random seed based on a crc calculation.

eeglstrt.c - initialize the generator based on three seed parameters.

eeglunif.c - generate a 32 bit fraction between zero and one.

Etaus generator.  Each subroutine corresponds to the eegl64
subroutine, above, with the same name and features.

etausabt.c

etausbit.c

etaus.c

etausdspl.c

etausfrac.c

etausinit.c

etausint.c

etauspwr.c

etausstrt.c

etausunif.c

freeall.c - free all memory allocated from the heap.

gen_curr_smpl.c - called by bld_curr_smpl, generate the
current sample.

getbyte.c - read one unsigned character from stdin.

getdie.c - read one random integer from dieharder.

permute.c - calculate permutations, used in the calculation
of expected run statistics.

shwsmpls.c - for debugging, display internal tables of counts.

--------------------------------------------------------------

----------------

If you have a random number generator that you want to include
in this repository, you are welcome to submit your generator for
inclusion.

Read the INSTALL and TESTING documents for more information
about how to use this repository.

