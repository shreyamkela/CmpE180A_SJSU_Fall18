#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{

	if(argc != 3) cerr << "usage: " << argv[0] << " <textfilename1> " << "<textfilename2>" << endl;
	else {

		ifstream read(argv[1]), read2(argv[2]);

		if(read.is_open() == false || read2.is_open() == false) cerr << "Error: Could not open file" << endl;
		// To check if the file can be opened or not

		else {

			//			To check if a file is empty:
			//			istream::peek() returns the constant EOF (which is not guaranteed to be equal to -1) when it detects end-of-file
			//			or error. To check robustly for end-of-file, do this:
			//
			//			int c = file.peek();
			//			if (c == EOF) {
			//			  if (file.eof())
			//			    // end of file
			//			  else
			//			    // error
			//			} else {
			//			  // do something with 'c'
			//			}
			//

			int c = read.peek();
			int d = read2.peek();
			if (c == EOF || d == EOF) {
			  if (read.eof() || read2.eof())
			    cerr << "Error: File is empty" << endl;
			  else
			    cerr << "Error: File unreadable" << endl;
			} else {

				string line,a,line2,a2;
				vector<vector<int>> matrix1,matrix2;
				int i=0,m=0;




				while(read.peek() == '\r' || read.peek() == '\n') read.get();
				// To check if the first few lines are empty in the file.
				// That is, it is not necessary that the matrix would start from the first line itself

				while(getline(read,line,'\r')) {
					if (line == "\n")
						continue;
					stringstream s(line);
					matrix1.push_back(vector<int>());
					while(s) {
						s >> a;
						if(a == "") continue;
						else matrix1[i].push_back(stoi(a));
						a = "";
					}
					i++;
				}
				read.close();
				//Close file so that cursor/stdin/stdout is available to the next file






				while(read2.peek() == '\r' || read2.peek() == '\n') read2.get();


				while(getline(read2,line2,'\r')) {
					if (line2 == "\n")
						continue;
					stringstream ss(line2);
					matrix2.push_back(vector<int>());
					while(ss) {
						ss >> a2;
						if(a2 == "") continue;
						else matrix2[m].push_back(stoi(a2));
						a2 = "";
					}
					m++;
				}
				read2.close();





				//If number of columns of first are equal to number of rows of second, then matrices are multipliable
				if(matrix1[0].size() == matrix2.size()) {

					int termSum=0,x=0;
					vector<vector<int>> matrix3;
					vector<int> matrix3col;

					//iterator not used as couldn't find solution for iterating two different 2D arrays simultaneously

					for(unsigned int p=0; p<matrix1.size();p++) {

						matrix3.push_back(matrix3col);
						for(unsigned int q=0; q<matrix2[0].size();q++) {

							termSum = 0;

							for(unsigned int r=0; r<matrix1[0].size();r++) {


								termSum += (matrix1[p][r]*matrix2[r][q]);


							}

							matrix3.at(x).push_back(termSum);

						}

						x++;

					}




					for(unsigned int f = 0; f<matrix3.size();f++) {

						for(unsigned int g = 0; g<matrix3[0].size();g++) {
							cout << setw(10) << left <<  matrix3[f][g] << " ";
						}
						if(f!=matrix3.size()-1) cout << "\n" << endl;
					}

				}
				else cerr << "Error: The matrices cannot be multiplied" << endl;




			}

		}
	}
}




