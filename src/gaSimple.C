/* ----------------------------------------------------------------------------
 /*
 
  Notice that one-point crossover is not necessarily the best kind of crossover
to use if you want to generate a 'good' genome with this kind of objective 
function.  But it does work.
---------------------------------------------------------------------------- */

#include <ga/GASimpleGA.h>	// we're going to use the simple GA
#include <ga/GA1DBinStrGenome.h> // and the 1D binary string genome
#include <ga/std_stream.h>

#define cout STD_COUT
  FILE *fp=fopen("binary.data","r");
float Objective(GAGenome &);	// This is the declaration of our obj function.
				// The definition comes later in the file.


int
main(int argc, char **argv)
{

// a seed to use (for testing purposes).  When you
// specify a random seed, the evolution will be exactly the same each time
// you use that seed number.

  for(int ii=1; ii<argc; ii++) {
    if(strcmp(argv[ii++],"seed") == 0) {
      GARandomSeed((unsigned int)atoi(argv[ii]));
    }
  }

// Declare variables for the GA parameters and set them to some default values.

  //int width    = 50;
  //int height   = 41;
  int length=719;
  int popsize  = 20;
  int ngen     = 4000;
  float pmut   = 0.01;
  float pcross = 0.9;

// Now create the GA and run it.  First we create a genome of the type that
// we want to use in the GA.  The ga doesn't operate on this genome in the
// optimization - it just uses it to clone a population of genomes.

  GA1DBinaryStringGenome genome(length, Objective);

// Now that we have the genome, we create the genetic algorithm and set
// its parameters - number of generations, mutation probability, and crossover
// probability.  And finally we tell it to evolve itself.

  GASimpleGA ga(genome);
  ga.populationSize(popsize);
  ga.nGenerations(ngen);
  ga.pMutation(pmut);
  ga.pCrossover(pcross);
  ga.nBestGenomes(10);
  ga.evolve();

// Now we print out the best genome that the GA found.

  cout << "The GA found:\n" << ga.statistics().bestPopulation() << "\n";

// That's it! 
fclose(fp);
  return 0;
}
 


float Objective(GAGenome& g) {
  GA1DBinaryStringGenome & genome = (GA1DBinaryStringGenome &)g;
  float score=0.0;
  int count=0;
  char binary[719];
  fgets(binary,sizeof(binary),fp);
 // while(fgets(binary,sizeof(binary),fp))
    {
	//  cout<<binary<<"~~";
	
	
  for(int i=0; i<genome.length(); i++)
  {
	  
	  //printf("%d\n",genome.gene(i));
	  char temp[1];
	  sprintf(temp,"%d",genome.gene(i));
	if(temp[0]==binary[i])
	{
		score++;
		//cout<<genome.gene(i);
		//cout<<score<<"-";
	}
  }
}
rewind(fp);
  return score;
}
