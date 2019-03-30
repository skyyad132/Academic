//Assignment no. 1 Weather Report
#include<iostream>
using namespace std;


class report
{
  private:
	  int day, htemp, ltemp, rain, snow;
  
  public:
	  report()                     		 		 		//default constructor
	  {
		  day = htemp = ltemp = rain = snow = 0;
	  }
	  
    report(int a, int b, int c, int d, int e)     				//parameterized constructor
	  { 
		  day = a;
		  htemp = b;
		  ltemp = c;
		  rain = d;
		  snow = e;
	  }
	
    report(report &R)                         					//Copy constructor
	  {
      day = R.day;
		  htemp = R.htemp;
		  ltemp = R.ltemp;
		  rain = R.rain;
		  snow = R.snow;
	  } 
    
    void getdata();
    void display();
    void avg(report R[31],int n);
};


void report :: getdata()
{
  cout<<"\nEnter Day of Month :";
  cin>>day;
  cout<<"Enter Highest Temperature :";
  cin>>htemp;
  cout<<"Enter Lowest Temperature :";
  cin>>ltemp;
  cout<<"Enter Amount Rain :";
  cin>>rain;
  cout<<"Enter Amount Snow :";
  cin>>snow;
}


void report :: display()
{
  cout<<"\n"<<day<<"\t"<<htemp<<"\t"<<ltemp<<"\t"<<rain<<"\t"<<snow;
}


void report::avg(report R[31],int n)
{
  int sumltemp = 0, sumhtemp = 0, sumrain = 0, sumsnow = 0;
  int altemp,ahtemp,arain,asnow;

  for (int i = 0; i < n; i++)
  {
	  sumhtemp=sumhtemp+R[i].htemp;
	  sumltemp=sumltemp+R[i].ltemp;
	  sumrain=sumrain+R[i].rain;
	  sumsnow=sumsnow+R[i].snow;
  }
  ahtemp = sumhtemp/n;
  altemp = sumltemp/n;
  arain = sumrain/n;
  asnow = sumsnow/n;

  cout<<"\nAverage of HighTemp=> "<<ahtemp;
  cout<<"\nAverage of LowTemp=> " <<altemp;
  cout<<"\nAverage of RainFall=> "<<arain;
  cout<<"\nAverage of SnowFall=> "<<asnow;
}


int main()
{
  int ch, n, i;
  report ob[31];

  report ob1;   							//default constructor get called
  report ob2(10,20,30,40,50);					//parameterized constructor get called
  report ob3(ob2);						//copy constructor get called

  cout<<"\nDefault constructor data";
  ob1.display();
  cout<<"\nParameterized constructor data";
  ob2.display();
  cout<<"\nCopy constructor data";
  ob3.display();

  do
  {
    cout<<"\n1:Accept Data\n2:Display Data\n3:Avg";
    cout<<"\nEnter choice=";	
    cin>>ch;

    switch(ch)
    {
      case 1:
        cout<<"Enter no of days";
        cin>>n;
        cout<<"\nEnter Data";

        for (i = 0; i < n; i++)
        {
          ob[i].getdata();
        }
        break;

      case 2:
        cout<<"\n"<<"Day"<<"\t"<<"HTemp"<<"\t"<<"LTemp"<<"\t"<<"Rain"<<"\t"<<"Snow";
        for (i = 0; i < n; i++)
        {
          ob[i].display();
        }
        break;
      
      case 3:
        ob1.avg(ob,n);
        break;
    }
  }
  while(ch<4);
}
