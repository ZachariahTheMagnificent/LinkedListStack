#include "Stack.h"

void Stack::Push( int val ) {
	if ( count == 0 ) {
		e = new Element( val, nullptr );
	} else {
		Element* temp = e;
		e = new Element( val, temp );
		temp->Next = e;
	}
	count++;
}

int Stack::Pop() {
	if(count > 0 ) {
		count--;
		Element* temp = e;
		const int retVal = e->Value;
		e = e->Previous;
		delete temp;
		temp = nullptr;
		return retVal;
	} else {
		return -1;
	}
}

int Stack::Size() const {
	return count;
}

bool Stack::Empty() const {
	return (count == 0);
}