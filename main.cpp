/*
 * Name: Sara Yacoub
 * This program takes a text file of commands regarding
 * creating, pushing values to and poping from stacks and queues
 * and writing the result to an output text file
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

#include "SimpleList.h"
#include "Stack.h"
#include "Queue.h"

//lists of stacks and queues
list<SimpleList<int> *> intLi;		//pointers to all stacks and queues of ints
list<SimpleList<double> *> douLi;	//pointers to all stacks and queues of doubles
list<SimpleList<string> *> strLi;	//pointers to all stacks and queues of strings

#include "functions.h"

int main(){

	string inputFile;
	cout << "Enter name of input file: ";
	cin >> inputFile;
	ifstream input(inputFile);

	string outputFile;
	cout << "Enter name of output file: ";
	ofstream output(outputFile);

	string command;
	getline(input, command);

	while(!command.empty()){
		output << "PROCESSING COMMAND: " << command << "\n";

		string words[3] = {"", "", ""};
		int curWord = 0;

		//This loop divides the command into words to be easily processed later
		for(int i = 0; i < command.length(); i++){
			char cur = command.at(i);
			if(cur != ' '){
				words[curWord] += cur;
			}else{
				curWord++;
			}
		}


		//finding the correct data type
		char type = words[1].at(0);

		//determing if the name of the SimpleList exists
		bool unique = true;
		if( type == 'i' ){
			unique = isUnique<int>(&intLi, words[1]);
		}else if( type == 'd' ){
			unique = isUnique<double>(&douLi, words[1]);
		}else if( type == 's' ){
			unique = isUnique<string>(&strLi, words[1]);
		}

		//determine if list is empty
		bool empty = true;
		if( type == 'i' ){
			empty = isEmpty<int>(&intLi, words[1]);
		}else if( type == 'd' ){
			empty = isEmpty<double>(&douLi, words[1]);
		}else if( type == 's' ){
			empty = isEmpty<string>(&strLi, words[1]);
		}
		
		if( !words[0].compare("create") ){
			if(unique){
				if( type == 'i' ){
					addList<int>(&intLi, words[1], words[2]);
				}else if( type == 'd' ){
					addList<double>(&douLi, words[1], words[2]);
				}else if( type == 's' ){
					addList<string>(&strLi, words[1], words[2]);
				}
			}else{
				output << "ERROR: This name already exists!\n";
			}
		}else if( !words[0].compare("push") ){
			if(unique){
				output << "ERROR: This name does not exist!\n";
			}else{
				if( type == 'i' ){
					SimpleList<int> *l;
					for(auto const& i: intLi){
						if( i->getName().compare(words[1]) == 0 ){
							l = i;
						}
					}
					l->push( stoi(words[2]) );
				}else if( type == 'd' ){
					SimpleList<double> *l;
					for(auto const& i: douLi){
						if( i->getName().compare(words[1]) == 0 ){
							l = i;
						}
					}
					l->push( stod(words[2]) );
				}else if( type == 's' ){
					SimpleList<string> *l;
					for(auto const& i: strLi){
						if( i->getName().compare(words[1]) == 0 ){
							l = i;
						}
					}
					l->push( words[2] );
				}
			}
		}else if( !words[0].compare("pop") ){
			if(unique ){
				output << "ERROR: This name does not exist!\n";
			}else{
				if(empty){
					output << "ERROR: This list is empty!\n";
				}else{
					string popped = "";
					if( type == 'i' ){
						SimpleList<int> *l;
						for(auto const& i: intLi){
							if( i->getName().compare(words[1]) == 0 ){
								l = i;
							}
						}
						int temp = l->pop();
						popped += temp;
					}else if( type == 'd' ){
						SimpleList<double> *l;
						for(auto const& i: douLi){
							if( i->getName().compare(words[1]) == 0 ){
								l = i;
							}
						}
						double temp = l->pop();
						popped += temp;
					}else if( type == 's' ){
						SimpleList<string> *l;
						for(auto const& i: strLi){
							if( i->getName().compare(words[1]) == 0 ){
								l = i;
							}
						}
						popped += l->pop();
					}
					output << "Value popped: " << popped << "\n";
				}
			}
		}

		getline(input, command);
	}

	output.close();

	return 0;
}
