#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{	
	//menu / basic greeting
	cout << "Please enter your Passphrase: ";
	string pass;
	cin >> pass;
	//truncate pass?
	int offset = 0;
	for(char c : pass){
		offset = offset + int(c);
	}
	
	cout << "offset: " << offset << endl;
	offset = offset % 255;
	cout << "mod offset: " << offset << endl;

	
	char ch;
	fstream file("hello.txt", ios::in | ios::out);  // Opens file for reading
	// Check if file opened successfully
	if (file.is_open()) {
    // File operations here
		cout << "File opened successfully." << endl;
		while(file.get(ch)){
			//if (isalpha(ch)){
				// Store the current position for writing
                streampos currentPos = file.tellg() - streampos(1);
				//modify ch
				ch =  ch + offset;
				if(ch > 255){
					ch = 255 - ch;
				}
				// Move back to write the modified character
                file.seekp(currentPos);
                file.put(ch);
                // Move forward to read next character
                file.seekg(currentPos + streampos(1));
			
			
		}
    	file.close();  // Close when done
	} else {
    // Handle error
		cout << "File not found." << endl;
	}

	return 0;
}