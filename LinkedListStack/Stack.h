#pragma once

class Stack {
public:
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;

	Stack() = default;

	~Stack() {
		delete e;
		e = nullptr;
	}

	Stack( const Stack& s ) {
		Element* temp = s.e;
		while ( temp != nullptr && temp->Previous != nullptr ) {
			temp = temp->Previous;
		}

		while ( temp != nullptr ) {
			this->Push( temp->Value );
			temp = temp->Next;
		}
	}

	Stack& operator=( const Stack& s ) {
		Element* temp = s.e;
		while ( temp != nullptr  && temp->Previous != nullptr ) {
			temp = temp->Previous;
		}

		while ( temp != nullptr ) {
			this->Push( temp->Value );
			temp = temp->Next;
		}

		return *this;
	}

private:
	int count = 0;


	class Element {
	public:
		int Value;
		Element* Next = nullptr;
		Element* Previous = nullptr;

		Element( const int val, Element* prev )
			:
			Value( val ),
			Previous( prev ) {
		}

		Element( const Element& e ) = delete;
		Element& operator=( const Element& e ) = delete;

		~Element() = default;
	};

	Element* e;
};