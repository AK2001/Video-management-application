//gui.h
#ifndef _GUI_H_
#define _GUI_H_

class Gui{
	public:
		
		
		int menu(){
			int choice;
			cout<<"1. Seach video title"
			<<"\t"
			<<"2. Add video"
			<<"\t"
			<<"3. Remove video"
			<<"\t"
			<<"4. List videos"
			<<"\t"
			<<"5. View stats"
			<<"\t"
			<<"0. Exit program"
			<<"\t"
			<<endl;
			cout<<"Enter a number: ";
			cin >> choice;
			
			return choice;
		}
		
	
};
#endif
