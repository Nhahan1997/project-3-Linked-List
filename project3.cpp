/*
 * project3.cpp
 *
 *  Created on: Mar 17, 2021
 *      Author: Nhan Le
 */

// Proejct 3 Spring 2021 Skeleton code

#include<iostream>

using namespace std;

// myString class and corresponding methods come here

// used to empty a given string A of length n
void emptyString (char* A, int n) {
	for (int i=0; i < n; i++) {
		A[i] = '\0';
	}
}

// copy a string A to B of length n
void stringCopy (char* A, int n, char* B) {
	for (int i=0; i < n; i++) {
		B[i] = A[i];
	}
}

class myString{
	friend ostream& operator << (ostream& s, myString& A);
protected:
	char* strArray;		// array of character
	int size;			// size of strArray

public:
	myString ();				// default constructor
	myString(char* inpStr);		// non-default constructor
	myString (myString& B);		// non-default constructor
	int Size();					// return size of array strArray
	char* getWord();			// return strArray
	myString& operator = (myString& B);		// assign myString object B to a myString object
	myString& operator = (char* B);			// assign char B to a myString object

};
ostream& operator << (ostream& s, myString& A) {
	s << A.strArray;
	return s;
}

myString::myString () {
	size = 0;
	strArray = new char[1];
	strArray[0] = '\0';
}

myString::myString (char* inpStr) {
	int i = 0;
	while (inpStr[i] != '\0')			// get the size of inpStr
		i++;
	size = i;
	strArray = new char[size];			// create new strArray with size is size
	emptyString (strArray, size+1);		// fill strArray with null element
	for (int j=0; j < size; j++)		// then assign all element of inpStr to strArray
		strArray[j] = inpStr[j];
}

// non default constructor - initialize object with an existing mystring object
myString::myString (myString& B) {
	delete [] strArray;
	strArray = NULL;
	size = B.size;			// assign size of B to size
	strArray = new char[size];			// create new strArray with size is size
	emptyString(strArray, size+1);		// fill strArray with null element
	stringCopy (B.strArray, size, strArray);	// copy all element in strArray of B to strArray
}

// Return strArray
char* myString::getWord()
{
	return strArray;
}

// getter for size of myString
int myString::Size () {
	return size;
}

myString& myString::operator = (char* B) {
	int i = 0;
	while (B[i] != '\0')	// get the size of B character
		i++;
	size = i;
	strArray = new char[size];		// assign new strArray with size is size
	emptyString(strArray, size+1);	// fill strArray with null element
	for (int j = 0; j < size; j++)	// then assign all element of inpStr to strArray
		strArray[j] = B[j];

	return *this;					// return strArray, size of array
}

// overloading = operator - initialize object with an existing mystring object
myString& myString::operator = (myString& B) {
	if(strArray != NULL)		// If array is not null, delete it
			delete[] strArray;
	size = B.size;				// assign size of B to size
	strArray = new char[size];	// create new strArray with size is size
	emptyString(strArray, size+1);				// fill strArray with null elements
	stringCopy(B.strArray, size, strArray);		// copy all element in strArray of B to strArray

	return *this;				// return strArray, size of array
}

// get one token from redirected input and return that string (alphanumeric)
char* getNextToken () {
	char* str = new char[50]; //assumes a max token size of 50
	emptyString (str, 50);

	char c;
	int i = 0;
	while (!cin.eof()) {	// check if the file have read to the end
		cin.get(c);			// get character c
		if (!cin.eof ()) {
			if ((c != '\n') && (c != ' ')) { 		// make sure c is not null or space
				if ( ((c >= 'a') && (c <= 'z')) ||
					 ((c >= 'A') && (c <= 'Z')) ||
					 ((c >= '0') && (c <= '9')) ||
					 c == '.' || c == '-' )		// getToken expensed to get period and hyphen mark
					str[i++] = c;	// if character is upper or lower case letter or number, add to str
			}
			else if ((c == '\n') && (i > 0))	// if c is null and c is not first character, just return str
				return str;
			else if ((c == ' ') && (i > 0))		// if c is space and c is not first character, just return str
				return str;
		}
	}
	if (i > 0) return str;
	else return NULL;
}

class webLinks {

	friend ostream& operator << (ostream& s, webLinks& A);
	protected:
		myString URL;
		int numLinks;
		webLinks** hyperLinks;
	public:
		webLinks ();
		webLinks (myString& x, int n);
		~webLinks ();
		int getNumLinks();
		webLinks* getHyperLink(int i);
		myString& getURL();
        void addSite(myString& t);
		void addNeighbor(webLinks& link);
        void setNeighbors(int nei);
};

ostream& operator << (ostream& s, webLinks& A)
{
    //TODO
	s << A.URL << ":" << endl;
	for(int i = 0; i < A.numLinks; i++){
		s << "**" << *A.hyperLinks[i] << endl;
	}

	return s;
}

// default constructor - initializes with size is zero
webLinks::webLinks()
{
    //TODO
	numLinks = 0;
	hyperLinks = new webLinks*[numLinks];

}

// non default constructor - initializes size of hyperLinks is n
webLinks::webLinks(myString& x, int n)
{
    //TODO
	numLinks = n;
	URL = x;
	hyperLinks = new webLinks*[numLinks];
}

//return URL
myString& webLinks::getURL()
{
	//TODO
	return URL;
}

//return size of hyperLinks which is numLinks
int webLinks::getNumLinks()
{
	//TODO
	return numLinks;
}

webLinks* webLinks::getHyperLink(int i)
{
	//TODO
	webLinks* hyper = new webLinks(URL,i);
	return hyper;
}

//destructor
webLinks::~webLinks()
{
    //TODO
	if(*hyperLinks != NULL) delete[] *hyperLinks;
	numLinks = 0;
}

//add the myString web site to URL of webLinks
void webLinks::addSite(myString& t)
{
    //TODO
	URL = t;	//utilize the overload operator to pass t to URL
}

//set number of neighbors of a webLinks, it is also the size of hyperLinks
void webLinks::setNeighbors(int nei)
{
    //TODO
	numLinks = nei;
}

//add the link at index neighbor to hyperLinks
void webLinks::addNeighbor(webLinks& link)
{
    //TODO
	webLinks** tempHyper = new webLinks*[numLinks];		//memory allocate
	*tempHyper[numLinks] = link;
	hyperLinks = tempHyper;
	++numLinks;

//	*hyperLinks[numLinks++] = link;		//add and increment to size of hyperLinks
}

int main () {

	int numSites;
	int siteNo;
	int numNeighbors;
	int neighbor;

    char* token;
	myString* tokenString;

	cin >> numSites;
    cout << "Number of websites: " << numSites << endl;
    cout << "~~~~~WebLinks:" << endl;

	webLinks* myWeb = new webLinks [numSites];
	for (int i=0; i < numSites; i++)
	{
        // read all URL and store them in the myWeb array of webLink objects
		token = getNextToken();		// read the next token
		if (token != NULL){
			tokenString = new myString(token);		//create a myString object with the token
			myWeb[i].addSite(*tokenString);			//add token to myWeb array
		}

	}

    // store the neighbours/hyperlinks
	for (int i = 0; i < numSites; i++)
	{
		cin >> siteNo >> numNeighbors;
		myWeb[i].setNeighbors(numNeighbors);
		for (int j=0; j < numNeighbors; j++)
		{
			cin >> neighbor;
			myWeb[siteNo].addNeighbor ((myWeb[neighbor]));
		}
	}

    // display all webLink objects using the overloaded << operator
	cout << "~~~~~WebLinks:" << endl;
	for (int i = 0; i < numSites; i++){
		cout << myWeb[i] << endl;
		cout << endl;
	}

	cout << "~~~~~Webpages contained as hyperLinks:" << endl;
    // display all the incoming nodes here

	delete [] myWeb;
	delete tokenString;

	return 0;
}






