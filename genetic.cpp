#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	int i,j,x,n,yc,b,count=0,countt=0,no;
	cout<<"Enter total chromosome to be created for getting corresponding genes as a solution-- ";
	cin>>no;
	double cr=.25,len=no*4; //10%
	double *result_of_eq=new double[no];
	double *fitness = new double[no];
	double *probabilty = new double[no];
	double *c = new double[no];
	int *save = new int[no*4];
	int *store = new int[count];	
	double 	total=0.0;	
	int **chromosome=0,**chromosomes=0,**chromo=0,**chromosomess=0;
	chromosome=new int *[no];
	chromosomes=new int *[no];
	chromo=new int *[no];
	chromosomess=new int *[no];
	for(i=0;i<no;i++)	//allocation of dynamic spaces
		{
			chromosome[i]=new int[4];
			chromosomes[i]=new int[no];
			chromo[i]=new int[4];
			chromosomess[i]=new int[4];
		}
	srand(time(NULL));	
//step-1: Populating pool	
	for(i=0;i<no;i++)	
		{
			for(int j=0;j<4;j++)	
				{
					chromosome[i][j]=(rand()%30)+1;	
				}
		}
//Step-2: Evaluation		
	for(int k=0;k<2000;k++)	//total iterations=2000
		{			
			count=0;
			total=0.0;
			cout<<"Iteration No."<<k<<endl;					
			for(i=0;i<no;i++)
				{
					j=0;
					yc=(((chromosome[i][j])+(2*(chromosome[i][j+1]))+(3*(chromosome[i][j+2]))+(10*(chromosome[i][j+3])))-30);		
						if(yc<0)
						{
							yc=-yc;
						}
						if(yc==0)
						{
							cout<<"Best breed of chromosomes are (as a solution):-"<<" "<<chromosome[i][j]<<","<<chromosome[i][j+1]<<","<<chromosome[i][j+2]<<","<<chromosome[i][j+3]<<endl;
							return 0;
						}												
					result_of_eq[i]=yc;
				}	
//Step-3: Selection
			for(i=0;i<no;i++)	
				{
					fitness[i]=(1/(1+result_of_eq[i]));	
					total=total+fitness[i];			
				}
			for(i=0;i<no;i++)
				{
					probabilty[i]=(fitness[i]/total);
				}
			for(i=0;i<no;i++)		//generating cumulative value: so as to compare this cumulative to that with randomly generated
				{
					if(i==0)
						{
							c[i]=probabilty[i];
						}
					else
						{
							c[i]=c[i-1]+probabilty[i];
						}
				}
			for(i=0;i<no;i++)
				{
					double r=rand()/((double) RAND_MAX);
					if(r<c[0])	//what if more than one r comes out to be less than that of c[0]?;
						{
							for(b=0;b<4;b++)
								{
									chromosomes[i][b]=chromosome[0][b];	//chromosomes will be stroed in temporary place so that it can later replace the exact position of originaly created chromosomes.
								}
						}
					else
						{
							for(j=0;j<no;j++)
								{
									if(r>c[j]&&r<c[j+1])
									{
										for(b=0;b<4;b++)
										{
												chromosomes[i][b]=chromosome[j+1][b];
										}
									}
								}
						}
				}			
			for(i=0;i<no;i++)
				{
					for(j=0;j<4;j++)
						{
								chromosome[i][j]=chromosomes[i][j];
						}
				}
//Step-4: Crossover
			double r=0;		
			for(i=0;i<no;i++)
				{
					r=rand()/((double) RAND_MAX);
					if(r<cr)		//selected chromo
					{
						count++;		//no of selected chromo
						store[count-1]=i;
							for(j=0;j<4;j++)
								{
									chromosomess[i][j]=chromosome[i][j];
								}
					}
				}
			if(count==0)
				{
					cout<<""<<endl;
				}
			else 	
				{
					for(i=0;i<count;i++)
						{
							for(j=0;j<4;j++)
								{
									chromo[store[i]][j]=chromosomess[store[i]][j];
								}
						}	
					for(i=0;i<count;i++)
						{
							n=i+1;
							x=((rand()%3)+1);	//CROSSover point
							for(j=x;j<4;j++)
								{
									if(i==(count-1))
										{
											chromo[store[i]][j]=chromosomess[store[0]][j];
										}									
									else
										{
											chromo[store[i]][j]=chromosomess[store[n]][j];
										}								
								}
						}			
					for(i=0;i<count;i++)
					{
						for(j=0;j<4;j++)
						{
							chromosome[store[i]][j]=chromo[store[i]][j];
						}
					}			
				}
//Step-5: Mutation				
			for(i=0;i<no;i++)
				{
					for(j=0;j<4;j++)
						{
							countt++;
							save[countt-1]=chromosome[i][j];	//saving random number, into one array for 2d matrix
						}
				}
			double pm=.1;
			int v=floor(pm*len);//rounding off value
			for(i=0;i<v;i++)
				{
					int pace=(rand()%(no*4))+1;// selecting any chromosome from set
					save[pace]=(rand()%30)+1;	//replacing selected chromosome
				}
			countt=0;
			for(i=0;i<no;i++)
				{
					for(int j=0;j<4;j++)	
						{
							countt++;
							chromosome[i][j]=save[countt-1];	
						}
				}
			countt=0;
		}
}
