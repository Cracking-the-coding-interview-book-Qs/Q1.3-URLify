//logic:
//Ek input string diya hoga along with some extra space and true length di hai.
//Ek observation hai ki '%20' ye add karne ke baad jo extra characters add hore hai(leaving the oroginal ones) 
//vo 2*no.of.whitespaces hai 
//do for loop chalao alag alag. First wali se no. of whitespaces count karo.
//aakhri index(of array not of extra space) se doosri for loop start karo.
//ek ek karke saare elements piche se copy karna start karo and jaha bhi whitespace mile, vaha '%20' ulte order me add karo.

//code delho thoda jyada samzega

//mai yaha string class use nhi kar raha hu kyuki basics clear hone chaiye.

//Issue:
//Look for corner cases if any

#include<iostream>
#include<cstring>    //to use strlen()

using namespace std; //isse baar baar std:: nhi likhna padta

int main()
{
	int i,whitespaces=0; 
	
	//given string 
	char given_string[17]={'M','r',' ','J','o','h','n',' ','S','m','i','t','h','\0','\0','\0','\0'};
	cout<<"\nGiven string is => "<<given_string;

	int trueLength=13;
	cout<<"\nGiven true length => "<<trueLength;
	
	int n=strlen(given_string);
	
	//count no. of whitespaces first.
	for(i=0;i<n;i++)
	{
		if(given_string[i]==' ')
		{
			whitespaces++;
		}
	}
	
	//we now need to keep the pointer on the last index(including additional space given)
	int index=trueLength+(2*whitespaces);
	int preserve_index=index;
	
	//iterate from last
	for(i=trueLength-1;i>=0;i--)
	{
		//agar whitespace ho to 3 characters insert karo
		if(given_string[i]==' ')
		{
			given_string[index-1]='0';
			given_string[index-2]='2';
			given_string[index-3]='%';
			//3 character add kiye to ab index 3 se reduce karo
			index=index-3;
		}
		//pehle to agar whitespace nahi ho and koi normal character ho, to copy karo last index pe(additional space wale) 
		else
		{
			given_string[index-1]=given_string[i];
			index--;
		}
	}
   cout<<"\n";
   //The modified string is
   for(i=0;i<preserve_index;i++)
   {
   		cout<<given_string[i];
   }
	return 0;
}
