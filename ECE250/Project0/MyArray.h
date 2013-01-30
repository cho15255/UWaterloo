#include <iostream>

using namespace std;

class Array {
        private:
                int *array;
                int array_size;

        public:
                Array( int = 10 );
                ~Array();

                // accessors
                int get( int ) const;
                int size() const;
		void print() const;
		void BinarySearch(Array, int, int);
		void IndexOf(Array, int);
		void Equals(int);

                // mutators
                void set( int, int );
                void resize( int );
		void Copy(Array, Array, int);
		void Sort(Array);
		void Reverse(Array);
};
