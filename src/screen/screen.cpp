#include "screen.h"

// Screen's constructor
Screen::Screen(string::size_type height, string::size_type width, char bkground):
	height_{height},// initialises height_ with height
	width_{width},  // initialises width_ with width
	_screen(height * width, bkground)	// size of _screen is height * width
										// all positions initialized with
										// character value of bkground
{ /* all the work is done in the member initialization list */ }

void Screen::forward()
{   // advance cursor_ one screen element
	++cursor_;

	// wrap around if the cursor_ is at the end of the screen
	if ( cursor_ == _screen.size()) home();

	return;
}

void Screen::back()
{   // move cursor_ backward one screen element
	// check for top of screen; wrap around
	if ( cursor_ == TOP_LEFT )
		end();
	else
		--cursor_;

	return;
}

void Screen::up()
{   // move cursor_ up one row of screen
	// do not wrap around
	if ( row() == 1 ) // at top?
		cursor_ = cursor_ + width_*(height_-1);
	else
		cursor_ -= width_;

	return;
}

void Screen::down()
{   // move cursor_ down one row of screen
	// do not wrap around
	if ( row() == height_ ) // at bottom?
		cursor_ = cursor_ - width_*(height_-1);
	else
		cursor_ += width_;

	return;
}

void Screen::move( string::size_type row, string::size_type col )
{   // move cursor_ to absolute position
	// valid screen position?
	if ( checkRange( row, col ) )
	{
		// row location
		auto row_loc = (row-1) * width_;
		cursor_ = row_loc + col - 1;
	}

	return;
}

char Screen::get( string::size_type row, string::size_type col )
{
	// position cursor_
	move( row, col );
	// the other get() member function
	return get();
}

void Screen::set( char ch )
{
	if ( ch == '\0' )
		cerr << "Screen::set warning: " << "null character (ignored).\n";
	else _screen[cursor_] = ch;

	return;
}

void Screen::set( const string& s ) // 4.2) Makes sure the string s input can not be changed in the function
{   // write string beginning at current cursor_ position
	auto space = remainingSpace();
	auto len = s.size();
	if ( space < len ) {
		cerr << "Screen::set - Truncating, "
			<< "space available: " << space
			<< ", string length: " << len
			<< endl;
		len = space;
	}

	_screen.replace( cursor_, len, s );
	cursor_ += len - 1;

	return;
}

void Screen::clear( char bkground )
{   // reset the cursor and clear the screen
	cursor_ = TOP_LEFT;
	// assign the string
	_screen.assign(
		// with size() characters
		_screen.size(),
		// of value bkground
		bkground
		);

	return;
}

void Screen::reSize( string::size_type h, string::size_type w, char bkground )
{   // can only *increase* a screen's size to height h and width w
	// remember the content of the screen
	string local{_screen};
	auto local_pos = TOP_LEFT;

	// replaces the string to which _screen refers
	_screen.assign(      // assign the string
		h * w,           // with h * w characters
		bkground         // of value bkground
		);

	// copy content of old screen into the new one
	for ( string::size_type ix = 0; ix < height_; ++ix )
	{ // for each row
		string::size_type offset = w * ix; // row position
		for ( string::size_type iy = 0; iy < width_; ++iy )
			// for each column, assign the old value
			_screen.at(offset + iy) = local[ local_pos++ ];
	}

	height_ = h;
	width_ = w;
	// cursor_ remains unchanged

	return;
}

void Screen::display() const // 4.2) Ensures the display function can not change the screen object
{
	for ( string::size_type ix = 0; ix < height_; ++ix )
	{ // for each row
		string::size_type offset = width_ * ix; // row position
		for ( string::size_type iy = 0; iy < width_; ++iy )
			// for each column, write element
			cout << _screen[ offset + iy ];
		cout << endl;
	}
	return;
}

bool Screen::checkRange( string::size_type row, string::size_type col ) const // 4.2) Stops the screen object from being modified, but does not stop the row and col variables from being changed
{   // validate coordinates
	if (row < 1 || row > height_ || col < 1 || col > width_)
	{
		cerr << "Screen coordinates ("<< row << ", " << col << " ) out of bounds.\n";
		return false;
	}
	return true;
}

void Screen::move(Screen::Direction dir){ // This function is redundant as all features are implemented with pre-existing functions which are easier to call
	switch (dir)
	{
	case Direction::HOME:
		home();
		break;
	case Direction::FORWARD:
		forward();
		break;
	case Direction::BACK:
		back();
		break;
	case Direction::UP:
		up();
		break;
	case Direction::DOWN:
		down();
		break;
	case Direction::END:
		end();
		break;
	default:
		cout << "Direction is not valid" << endl;
		break;
	}
}

// Existing interface can be used to implement the function
/* This function does not form part of the responsibilities of the screen object as it is not useful in interfacing or setting up the screen.
The square can be implemented outside the class. */
void Screen::square(int row, int col, int length){
	// Furthest row and column from the input
	int maxRow = row+length-1;
	int maxCol = col+length-1;
	// Error checking
	if((maxRow > height_) && (maxCol > width_)){
		cerr<< "Screen::square - There are not enough rows or columns for the specified square"<< endl;
		return;
	}
	if(maxRow > height_){
		cerr<<"Screen::square - Not enough rows for the specified square"<<endl;
		return;
	}
	if(maxCol > width_){
		cerr<<"Screen::square - Not enough columns for the specified square"<<endl;
		return;
	}
	// Creates square with 'X' edges and ' ' inside
	for(int curRow = row; curRow < row+length; curRow++){
		for(int curCol = col; curCol < col+length;curCol++){
			move(curRow,curCol);
			if((curRow == row)||(curRow == maxRow)||(curCol == col)||(curCol == maxCol)){
				set('X');
			}
			else{
				set(' ');
			}
		}
	}
	return;
}

string::size_type Screen::remainingSpace() const
{   // includes current position
	auto size = width_ * height_;
	return(size - cursor_);
}

string::size_type Screen::row() const
{   // return current row
	return (cursor_ + width_)/width_;
}
