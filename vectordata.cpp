//vectordata.cpp
#include <iomanip>

#include "vectordata.h"

	void VectorVideoData::populate(string filename){
		
		ifstream infile;
		VideoData anItemdata;
		infile.open(filename.c_str());
		
		while(infile){
			infile >> anItemdata;
			data.push_back(anItemdata);
		}
	}
	
	bool VectorVideoData::exists (string title){
		
		for(int i=0;i<data.size();i++)
			if(data[i].getTitle() == title)
				return true;
		return false;	
	}
	
	VideoData& VectorVideoData::findByTitle(string title){
		for(int i=0;i<data.size();i++)
			if(data[i].getTitle() == title)
				return data[i];
	}
	
	void VectorVideoData::save(string filename){
		ofstream fileOut;
		fileOut.open(filename.c_str());
		int spacing = 34;//NOTE: if u want the user to be able to enter a title of more than 25 character add +1 for every character
		fileOut << left <<setw(spacing)<<setfill(' ')<<"Videos\nTitle"; //Header of the .txt file using the ionmanip library
		fileOut << left << setw(spacing-20) << setfill(' ') << "Minutes";
   		fileOut << left << setw(spacing-22) << setfill(' ') << "Size (mb)";
    	fileOut << left << "Date (dd/mm/yy)";
   		fileOut<<endl; 
		
		
		for(int i=0;i<data.size();i++) //Data
				fileOut<<data[i]<<endl;
		fileOut.close();
	}
	
	ostream& operator << (ostream &out, VectorVideoData &vector){
		for(int i=0;i<vector.data.size();i++)
			out<<vector.data[i]<<endl;
		return out;
	}

