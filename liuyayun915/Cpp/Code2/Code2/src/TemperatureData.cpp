#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void Print_In_Three_Formats(void);
int Compare_If_Is_Equal(double v1, double v2);
double Compare_Two_Temperatures(double v1, double v2);
double Process_Temperatures(string Scale,double Temperature_data);



double Temperature[3] = { 0, 0 , 0}; // Temperature[0] = Temperatue in Fahrenheit;
                                     // Temperature[1] = Temperatue in Celsius;
                                     // Temperature[2] = Temperatue in Kelvin;
struct TemperatureData{
  string scale;
  double temperature;
  int year;                          // construct a class which contains three data members
};


int main()
{
	double Largest_Temperature;
    double Temperature1_In_Fahrenheit,Temperature2_In_Fahrenheit;
    TemperatureData Temperature0, Temperature1, Temperature2;

    cout << "Please input the scale of the temperature: F(Fahrenheit), C(Celsius), or K(Kelvin).\n";
    cin >> Temperature0.scale;
    cout << "The temperature is"<<endl;
    cin >> Temperature0.temperature;
    Process_Temperatures(Temperature0.scale,Temperature0.temperature);
    Print_In_Three_Formats();

    cout << "Please input the scale of the first temperature: F(Fahrenheit), C(Celsius), or K(Kelvin).\n";
    cin >> Temperature1.scale;
    cout << "Please input the first temperature.\n";
    cin >> Temperature1.temperature;


    cout << "Please input the scale of the second temperature: F(Fahrenheit), C(Celsius), or K(Kelvin).\n";
    cin >> Temperature2.scale;
    cout << "Please input the second temperature.\n";
    cin >> Temperature2.temperature;

    if( Temperature1.scale == Temperature2.scale){
    	if( Compare_If_Is_Equal(Temperature1.temperature, Temperature2.temperature) )
    		cout << "They're equal. The temperature is"<<" "<<Temperature1.temperature<<"��"<<Temperature1.scale<<"."<<endl;
    	else{
    		Largest_Temperature = Compare_Two_Temperatures(Temperature1.temperature,Temperature2.temperature);
    		cout << "The larger one of two temperatures is"<<" "<<Largest_Temperature<<"��"<<Temperature1.scale<<"."<<endl;
    		}
    }


    else
    {

    	if( Temperature1.scale == "F"){
    		Temperature2_In_Fahrenheit = Process_Temperatures(Temperature2.scale,Temperature2.temperature);
    		if( Compare_If_Is_Equal(Temperature1.temperature,Temperature2_In_Fahrenheit) )
    			cout <<"They're equal. The temperature is"<<" "<<Temperature1.temperature<<"��"<<Temperature1.scale<<"."<<endl;
    		else{
    			Largest_Temperature = Compare_Two_Temperatures(Temperature1.temperature,Temperature2_In_Fahrenheit);
    			if( Largest_Temperature == Temperature1.temperature)
    				cout << "The larger one of two temperatures is"<<" "<<Largest_Temperature<<"��"<<Temperature1.scale<<"."<<endl;
    			else
    				cout << "The larger one of two temperatures is"<<" "<<Temperature2.temperature<<"��"<<Temperature2.scale<<"."<<endl;
         	 	 }
    	}

    	else if( Temperature2.scale == "F"){
        	Temperature1_In_Fahrenheit = Process_Temperatures(Temperature1.scale,Temperature1.temperature);
        	if( Compare_If_Is_Equal(Temperature1_In_Fahrenheit,Temperature2.temperature) )
        	    cout <<"They're equal. The temperature is"<<" "<<Temperature1.temperature<<"��"<<Temperature1.scale<<"."<<endl;
        	else{
        		Largest_Temperature = Compare_Two_Temperatures(Temperature2.temperature,Temperature1_In_Fahrenheit);
        		if( Largest_Temperature == Temperature2.temperature)
        			cout << "The larger one of two temperatures is"<<" "<<Largest_Temperature<<"��"<<Temperature2.scale<<"."<<endl;
        		else
        			cout << "The larger one of two temperatures is"<<" "<<Temperature1.temperature<<"��"<<Temperature1.scale<<"."<<endl;
         	 	 }
    	}

    	else if( Temperature2.scale == "C"){
        		Temperature1_In_Fahrenheit = Process_Temperatures(Temperature1.scale,Temperature1.temperature);
        		Temperature2_In_Fahrenheit = Process_Temperatures(Temperature2.scale,Temperature2.temperature);
        		if( Compare_If_Is_Equal(Temperature1_In_Fahrenheit,Temperature2_In_Fahrenheit) )
        			cout <<"They're equal. The temperature is"<<" "<<Temperature1.temperature<<"��"<<Temperature1.scale<<"."<<endl;
        		else{
        			Largest_Temperature = Compare_Two_Temperatures(Temperature2_In_Fahrenheit,Temperature1_In_Fahrenheit);
        			if( Largest_Temperature == (Temperature1.temperature* 9.0/5.0 +32.0) )
        				cout << "The larger one of two temperatures is"<<" "<<Temperature1.temperature<<"��"<<Temperature1.scale<<"."<<endl;
        			else
        				cout << "The larger one of two temperatures is"<<" "<<Temperature2.temperature<<"��"<<Temperature2.scale<<"."<<endl;
    			}
    	}

    	else{
    				Temperature1_In_Fahrenheit = Process_Temperatures(Temperature1.scale,Temperature1.temperature);
    				Temperature2_In_Fahrenheit = Process_Temperatures(Temperature2.scale,Temperature2.temperature);
    				if( Compare_If_Is_Equal(Temperature1_In_Fahrenheit,Temperature2_In_Fahrenheit) )
    				    cout <<"They're equal. The temperature is"<<" "<<Temperature1.temperature<<"��"<<Temperature1.scale<<"."<<endl;
    				else{
    					Largest_Temperature = Compare_Two_Temperatures(Temperature2_In_Fahrenheit,Temperature1_In_Fahrenheit);
    					if( Largest_Temperature == (Temperature2.temperature* 9.0/5.0 +32.0) )
    						cout << "The larger one of two temperatures is"<<" "<<Temperature2.temperature<<"��"<<Temperature2.scale<<"."<<endl;
    					else
    						cout << "The larger one of two temperatures is"<<" "<<Temperature1.temperature<<"��"<<Temperature1.scale<<"."<<endl;
    				}
    	}
    }

	return 0;

}

int Compare_If_Is_Equal(double v1, double v2)
{
  if ( v1 == v2) return 1;
  else return 0;

}

double Compare_Two_Temperatures(double v1, double v2)
{
	if( v1 > v2) return v1;
	else  return v2;


}


double Process_Temperatures(string Scale,double Temperature_data)
{
  double Temp_buffer[3];

  if( Scale == "F")
   {
     Temp_buffer[0] = Temperature_data;
     Temp_buffer[1] = (Temperature_data - 32.0) * 5.0/9.0;
     Temp_buffer[2] = (Temperature_data - 32.0) * 5.0/9.0 + 273.15;
    }

   if( Scale == "C")
    {
     Temp_buffer[0] = Temperature_data * 9.0/5.0 +32.0;
     Temp_buffer[1] = Temperature_data;
     Temp_buffer[2] = Temperature_data +273.15;
     }

   if( Scale == "K")
     {
	 Temp_buffer[0] = (Temperature_data - 273.15) * 9.0/5.0 +32.0;
     Temp_buffer[1] = Temperature_data - 273.15;
     Temp_buffer[2] = Temperature_data;
     }

   for(int i=3; i>=0; i--)
     Temperature[i] = Temp_buffer[i];

   return Temp_buffer[0];
}

void Print_In_Three_Formats(void){
	cout <<"The temperature in three formates is :\n"<<endl;
    cout << Temperature[0] << "��F,\n"<<Temperature[1] << "��C,\n"<< Temperature[2] << "��K.\n" <<endl;
}
