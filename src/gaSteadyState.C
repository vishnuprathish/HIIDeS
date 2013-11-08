/* ----------------------------------------------------------------------------
 
 one-point crossover is not necessarily the best kind of crossover
to use if we want to generate a good genome with this kind of objective 
function.  But it does work.
---------------------------------------------------------------------------- */

#include <ga/GASStateGA.h>	// we're going to use the steady state GA
#include <ga/GA1DBinStrGenome.h> // and the 1D binary string genome
#include <ga/std_stream.h>

#define cout STD_COUT
  FILE *fp=fopen("binary.data","r");
float Objective(GAGenome &);	// This is the declaration of our obj function. - used for a linear fitness measure
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
  int length=730;
  int popsize  = 100;
  int ngen     = 4000;
  float pmut   = 0.001;
  float pcross = 0.9;

// Now create the GA and run it.  Fist we create a genome of the type that
// we want to use in the GA.  The ga doesn't operate on this genome in the
// optimization - it just uses it to clone a population of genomes.

  GA1DBinaryStringGenome genome(length, Objective);

// Now that we have the genome, we create the genetic algorithm and set
// its parameters - number of generations, mutation probability, and crossover
// probability.  And finally we tell it to evolve itself.

  GASteadyStateGA ga(genome);
  ga.populationSize(popsize);
  ga.nGenerations(ngen);
  ga.pMutation(pmut);
  ga.pCrossover(pcross);
  ga.nBestGenomes(90);
  ga.evolve();

// Now we print out the best genome that the GA found.

  cout << "The GA found:\n" << ga.statistics().bestPopulation() << "\n";

// That's it! 
fclose(fp);
  return 0;
}
 


float Objective(GAGenome& g) {
  GA1DBinaryStringGenome & genome = (GA1DBinaryStringGenome &)g;
//  printf("something happend");
  float score=0.0;
  int count=0;
  char binary[730];
 // fgets(binary,sizeof(binary),fp);
 // cout<<binary<<"\n";
  while(fgets(binary,sizeof(binary),fp))
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
//printf("what happend");
if(binary[729]=='0')
score=-score;

  return score;
}
