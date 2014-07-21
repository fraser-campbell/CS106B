/*
 * File: map_city.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: [TODO: enter section leader here] 
 * 
 */

 #include <string>
 #include <map>
 #include <vector>
 #include <iostream>

 using namespace std;

 struct pointT {
 	int x,y;
 };

 struct cityT {
 	string name;
 	pointT coordinates;
 };

 typedef map<string, cityT> mapping;
 typedef vector<cityT> cities;


 void create_vector_data(cities &citys){
 		cityT city1 = {
		"Glasgow", {10, 20}
	};
		cityT city2 = {
		"Bangkok", {20, 50}
	};
		cityT city3 = {
		"Seattle", {100, 10}
	};
 	citys.push_back(city1);
 	citys.push_back(city2);
 	citys.push_back(city3);
 }

 void create_map(cities &citys, mapping &my_map){
 	for(cities::iterator itr=citys.begin(); itr<citys.end(); ++itr){
		string key = to_string(itr->coordinates.x) + ", " + to_string(itr->coordinates.y);
		// cout << key << endl;
		if(my_map.find(key) == my_map.end()){ //Insert a key if it doesn't exist
			my_map.insert(make_pair(key, *itr));
		}
	}
 }

 void print_map(mapping &my_map){
 	for(mapping::iterator itr=my_map.begin(); itr != my_map.end(); ++itr){
 		cout << "The city of: " << itr->second.name <<  "   " << "Coordinates: " << itr->second.coordinates.x << ", " <<  itr->second.coordinates.y << endl;
 	}
 }

 int main(){

	mapping my_map;
	cities citys; //Create the vector of cities
	create_vector_data(citys);
	create_map(citys, my_map);
	print_map(my_map);

 	return 0;
 }
