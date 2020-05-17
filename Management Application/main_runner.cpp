
#include <cmath>

#include "videodata.h"
#include "vectordata.h"
#include "gui.h"
#include "functions.h"


int main() {
cout<<"----------------------------------------------CourseWork-----------------------------------------------\n"
	<<endl;
	
//Note: don't force close 
//The app saves in .txt when case is 0 


VectorVideoData videos; //Creats an object of the VectorVideoData class. NOTE: .data is the vector
//videos is going to be used in order to save into .txt file and videos.data in memory

VideoData a("First Video","11/5/2020",42.3,700,"|","|","|");//The first 3 default videos as VideoData objects
VideoData b("Second Video","9/9/2001",11.2,1070,"|","|","|");//NOTE: <"|"> is only for decoration purposes and can be changed
VideoData c("Third Video","24/1/2019",6.5,1230,"|","|","|");


videos.data.push_back(a);//Adding the first 3 video objects to the videos vector
videos.data.push_back(b);
videos.data.push_back(c);

Gui gui;
VideoData newVideo;//Used in Case 2
int index;
	while(1){
		int choice=gui.menu();
		
		switch(choice){
			case 1: cout<<"You selected to search "<<endl;
					
				videosSearcher(videos);
					
				break;
			case 2: cout<<"You selected to add a video"<<endl;
			
				videos.data.push_back(read(newVideo));//Adds a new object to the vector videos (it saves objects in memory)
			
				break;
			case 3: cout<<"You selected to remove a video"<<endl;
				
				index=unwantedVideoIndex(videos);
				if(index>=0){
					
					videos.data.erase(videos.data.begin()+index);
				}
				break;	
			case 4: cout<<"You selected to view the videos"<<endl;
				
				videoListShower(videos);
					
				break;
			case 5: cout<<"You selected to view the stats"<<endl;

				statsShower(videos);
				
				break;
			case 0:
			default:cout<<"You selected to exit"<<endl;

			videos.save("videos.txt");//Creates and writes all the video objects to a .txt file
			videos.populate("videos.txt");
			return 0;	
			
		}
	}
}
