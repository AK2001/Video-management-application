//vectordata.h
#ifndef _VECTORDATA_H_
#define _VECTORDATA_H_

#include <iostream>
#include <fstream>
#include <vector>

#include "videodata.h"

using namespace std;

class VectorVideoData{
	public:
		vector<VideoData> data;
		
		void save(string filename);
		
		void populate(string filename);
		bool exists (string title);
		VideoData &findByTitle (string title);
		
		friend ostream& operator << ( ostream &out, VectorVideoData &vector);
};
#endif

