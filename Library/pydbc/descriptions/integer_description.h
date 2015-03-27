#pragma once

#include <pydbc/description.h>

namespace pydbc {

/**
 * @brief Represents a description to bind a buffer holding integer values
 */
class integer_description : public description {
public:
	integer_description();
	~integer_description();
private:
	std::size_t do_element_size() const final;
	SQLSMALLINT do_column_type() const final;
	SQLSMALLINT do_column_sql_type() const final;
	field do_make_field(char const * data_pointer) const final;
};

}