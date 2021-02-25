#ifndef DATA_CLASS_HPP
# define DATA_CLASS_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <string>
# include <cmath>
# include <ctime>
# include <stdexcept>
# include <cstdlib>
# include <typeinfo>
# include <limits>

class DataClass {
	public:
		class DataNotFound : public std::exception {
			public:
				virtual const char * what() const throw();
		};
		DataClass( void );
		DataClass( DataClass const & );
		DataClass & operator=( DataClass const & );
		~DataClass( void );
	private:
		std::vector<uint64_t> *_vF;
};

#endif