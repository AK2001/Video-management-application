//videodata.h
#ifndef _VIDEODATA_H_
#define _VIDEODATA_H_

#include<iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std; 

class VideoData{
	private:
		string spacer;
		string spacer1;
		string spacer2;
		string title;
		string date;
		double duration;
		double size;
		
	public:
	//constructors
	VideoData(){
	}
	
	VideoData	(string aTitle, string aDate, double theDuration, double theSize, string aSpacer, string aSpacer1, string aSpacer2)
	{//the spacer viariables are for decoration ONLY and can be changed to whatever the programmer wants
		spacer= aSpacer;
		spacer1= aSpacer1;
		spacer2= aSpacer2;
		
		title = aTitle;
		date= aDate;
		
		duration = theDuration;
		size = theSize;
	}
	//setters
	void setSpacer (string aSpacer){
		spacer=aSpacer;
	}
	
	void setSpacer1 (string aSpacer1){
		spacer1=aSpacer1;
	}
	
	void setSpacer2 (string aSpacer2){
		spacer2=aSpacer2;
	}
				
	void setTitle(string aTitle)
	{
		title = aTitle;
	}
	
	void setDuration(double theDuration)
	{
		duration = theDuration;
	}
	
	void setDate(string theDate)
	{
		date = theDate;
	}
	
	void setSize(double theSize)
	{
		size = theSize;
	}
	
	//getters
	
	string getTitle()
	{
		return title;
	}
	
	string getDate(){
		return date;
	}
	
	double getDuration()
	{
		return duration;
	}
	
	double getSize()
	{
		return size;
	}
	
	
	friend   istream&  operator >> (  istream   & in,    VideoData  &data)
	{
		return	in >>data.title 
			>> data.duration
			>> data.date
			>> data.size
			>>data.spacer
			>>data.spacer1
			>>data.spacer2;
	}
	
	friend   ostream&  operator << ( ostream  & out,   VideoData  &data)
	{
		const int titleWidth  = 25;//NOTE: if u want the user to be able to enter a title of more than 25 character add +1 for every character (also change in main_runner.cpp)
		const int dataWidth = 12;
		
		return	out	<< left << setw(titleWidth) <<data.title 
			<<" "
		    <<data.spacer
   			<<" "
		    << left << setw(dataWidth) << data.duration
		    <<" "
		    <<data.spacer1
		    <<" "
		    << left << setw(dataWidth) << data.size
		    <<" "
		    <<data.spacer2
		    <<" "
		    << left << setw(dataWidth) << data.date
		    <<endl;
	}		
	
};

#endif

