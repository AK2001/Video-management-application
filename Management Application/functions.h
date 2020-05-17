//functions.h

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "videodata.h"
#include "vectordata.h"

#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>



using namespace std; 



//------------------Case 1 functions for main------------------
//This function prompts the user to enter a video title and then searches the memory and outputs if the video object with the specific video title attribute 
//exists or not.

	void videosSearcher(VectorVideoData &videoList){
		string title,maxDurationTitle;//Used in Case 1
		int checker=0;//Used in Case 1
		int spacing =29;//NOTE: If u want to be able to input video title >25 characters add +1 to <spacing>. (also change in videodata.h)

			cout<<"Enter the video title you want to search: ";
					cin.ignore();
					getline(cin,title);
					while(title.length()>spacing-1){ //NOTE: If u want to be able to input video title >25 characters add +1 to <spacing>.
						cout<<"Please enter a video title under 25 characters: ";
						getline(cin,title);
					}
					for(int i=0;i<videoList.data.size();i++){
						if(videoList.data[i].getTitle()==title){
							checker++;
							cout<<"The video exists.\n"
								<<"It is: "
								<<videoList.data[i].getDuration()
								<<" minutes, "
								<<videoList.data[i].getSize()
								<<" MB and was uploaded on "
								<<videoList.data[i].getDate()
								<<"\n"
								<<endl;
						}
					}
					if (checker==0){
						cout<<"The video doesn't exist. Try again.\n"
							<<endl;
					}
	}
	
	
//------------------Case 2 functions for main------------------
//This function reads a new object 

	VideoData &read(VideoData &newVideo){ // inputs the attributes for each object created
		string spacer,spacer1,spacer2,newTitle,newDate;//The spacer variables appliy a spacer between each attribute
		double newDuration,newSize;
		
		cin.ignore();
		cout<<"Give video Title (max 25 characters long): "; //25 characters long but can be changed 
		getline(cin,newTitle);
		while(newTitle.length()>25){
			cout<<"Please enter a valid video title (max 25 characters long) ";
			getline(cin,newTitle);
		}
		newVideo.setTitle(newTitle);
		
		spacer="|";
		newVideo.setSpacer(spacer);
		
		cout<<"Give the duration of the video in minutes: ";
		cin>>newDuration;
		newVideo.setDuration(newDuration);
		
		spacer1="|";
		newVideo.setSpacer1(spacer1);
		
		cout<<"Give the size of the video in MB: ";
		cin>>newSize;
		newVideo.setSize(newSize);
		
		spacer2="|";
		newVideo.setSpacer2(spacer2);
		
		cout<<"Give video date (dd/mm/yy): ";
		cin>>newDate;
		newVideo.setDate(newDate);
		
		return newVideo;
	}
	
//------------------Case 3 functions for main------------------
//This function deletes a specific video from memory

	bool videoExists(VectorVideoData &videoList, string title){
		int exists=0;
		
		for(int i=0;i<videoList.data.size();i++){
			if(videoList.data[i].getTitle()==title){
				exists++;		
			}
		}
		
		if (exists==0){
			return true;
		}else{
			return false;
		}
	}

	int unwantedVideoIndex(VectorVideoData &videoList){
		string title;
		int index=-1;
		
		cout<<"Enter the video title you want to remove. Else enter <0> to exit: ";
		cin.ignore();
		getline(cin,title);
		
		while(videoExists(videoList,title)&&title!="0"){
			cout<<"The video doesn't exists. Try again or enter <0> to exit: ";
			getline(cin,title);	
		}
		
		if(title!="0"){
			for(int i=0;i<videoList.data.size();i++){
				if(videoList.data[i].getTitle()==title){
					index=i;	
					cout<<"Video: "
					<<title
					<<" was successfully erased from memory\n"
					<<endl;	
				}
			}	
		}else{
			cout<<"You selected to exit."<<endl;
		}
		
		
		return index;			
	}


//------------------Case 4 functions for main------------------
//This function lists the videos from memory

void videoListShower(VectorVideoData &videoList){
	int spacing =29;//NOTE: If u want to be able to input video title >25 characters add +1 to <spacing>. (also change in videodata.h)
	cout << left << setw(spacing) << "Video Title";
			cout << left << setw(spacing-14) << "| Length (min)";
			cout << left << setw(spacing-14) << "| Size (mb)";
			cout << left << "| Date\n";
			cout <<endl;
			
			for (int i =0;i<videoList.data.size();i++){	
				for(int j=0;j<spacing*3;j++) { //Optional for(), only for decoration purposes
					cout<<"-";
				}
				cout<<endl
					<<i+1
					<<". "
					<<videoList.data[i]//here is when the actual video objects are displayed 
					<<endl;
			}
}


//------------------Case 5 functions for main------------------

//The first SIX (6) are responsible for finding which video, by index, is the longest/shortest/largest/smaller as well as total duration and size
//statsShower uses <iomanip> to output those stats clean and nice

double findMaxDuration(VectorVideoData &videoList){
	double maxD=-1;
	int maxDurationIndex=0;
	for(int i=0;i<videoList.data.size();i++){
		if(videoList.data[i].getDuration()>maxD){
				maxD=videoList.data[i].getDuration();
				maxDurationIndex=i;
			}	
	}	
	return maxDurationIndex;
}	

double findMaxSize(VectorVideoData &videoList){
	double maxS=-1;
	int maxSizeIndex=0;
	for(int i=0;i<videoList.data.size();i++){
		if(videoList.data[i].getSize()>maxS){
				maxS=videoList.data[i].getSize();
				maxSizeIndex=i;
			}	
	}	
	return maxSizeIndex;
}	

double findMinDuration(VectorVideoData &videoList){
	double minD=pow(10,10);
	int minDurationIndex=0;
	for(int i=0;i<videoList.data.size();i++){
		if(videoList.data[i].getDuration()<minD){
			minD=videoList.data[i].getDuration();
			minDurationIndex=i;
		}
	}

	return minDurationIndex;
}	

double findMinSize(VectorVideoData &videoList){
	double minS=pow(10,10);	
	int minSizeIndex=0;
	for(int i=0;i<videoList.data.size();i++){
		if(videoList.data[i].getSize()<minS){
			minS=videoList.data[i].getSize();
			minSizeIndex=i;
		}
	}
	return minSizeIndex;
}	

double findTotalDuration(VectorVideoData &videoList){
	double totalDuration=0;
	for(int i=0;i<videoList.data.size();i++){
		totalDuration += videoList.data[i].getDuration();
	}
	return totalDuration;
}

double findTotalSize(VectorVideoData &videoList){
	double totalSize=0;
	for(int i=0;i<videoList.data.size();i++){
		totalSize += videoList.data[i].getSize();
	}
	return totalSize;
}

void statsShower(VectorVideoData &videosList){
	
	int totalVideos=videosList.data.size();
	double totalDuration = findTotalDuration(videosList);
	double totalSize = findTotalSize(videosList);
	
	double longestVid = findMaxDuration(videosList);
	double shortestVid = findMinDuration(videosList);
	double largestVid = findMaxSize(videosList);
	double smallestVid = findMinSize(videosList);
	
	
	const char separator    = ' ';
	const int titleWidth     = 25;
	const int dataWidth      = 12;	
	
	cout << left << setw(titleWidth) << setfill(separator) << "Total Videos:";
	cout << left << setw(dataWidth) << setfill(separator) << totalVideos;
	cout << endl;
	
	cout << left << setw(titleWidth) << setfill(separator) << "Total duration (min):";
	cout << left << setw(dataWidth) << setfill(separator) << totalDuration;
	cout << endl;
	
	cout << left << setw(titleWidth) << setfill(separator) << "Total Size (mb):";
	cout << left << setw(dataWidth) << setfill(separator) << totalSize;
	cout <<"\n"<< endl;
	
	cout << left << setw(titleWidth) << setfill(separator) << "Average duration (min):";
	cout << left << setw(dataWidth) << setfill(separator) << totalDuration/totalVideos;
	cout << endl;
	
	cout << left << setw(titleWidth) << setfill(separator) << "Average size (mb):";
	cout << left << setw(dataWidth) << setfill(separator) << totalSize/totalVideos;
	cout <<"\n"<<  endl;
	
	cout << left << setw(titleWidth) << setfill(separator) << "Longest video (min):";
	cout << left << "No." << longestVid+1 << " - ";
	cout << left << setw(titleWidth) << setfill(separator) << videosList.data[longestVid].getDuration();
	
	cout << left << setw(titleWidth) << setfill(separator) << "Shortest video (min):";
	cout << left << "No." <<  shortestVid+1 << " - ";
	cout << left << setw(titleWidth) << setfill(separator) << videosList.data[shortestVid].getDuration();
	cout << endl;
	
	cout << left << setw(titleWidth) << setfill(separator) << "Largest video (mb):";
	cout << left << "No." <<  largestVid+1 << " - ";
	cout << left << setw(titleWidth) << setfill(separator) << videosList.data[largestVid].getSize();
	
	cout << left << setw(titleWidth) << setfill(separator) << "Smallest video (mb):";
	cout << left << "No." <<  smallestVid+1 << " - ";
	cout << left << setw(titleWidth) << setfill(separator) << videosList.data[smallestVid].getSize();
	cout <<"\n"<<  endl;
		
};
#endif
