﻿//------------------------------------------------------------------------------
// <copyright project="BEmu_cpp" file="src/ReferenceDataRequest/ElementReferenceArray.cpp" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------

#include "ReferenceDataRequest/ElementReferenceArray.h"
#include "BloombergTypes/Name.h"
#include "Types/IndentType.h"

namespace BEmu
{
	namespace ReferenceDataRequest
	{
		ElementReferenceArray::ElementReferenceArray(const std::string& name, const std::vector<ElementPtr*>& elements)
		{
			this->_name = name;
			this->_values = elements;
		}

		Name ElementReferenceArray::name() const { return Name(this->_name.c_str()); }
		size_t ElementReferenceArray::numValues() const { return this->_values.size(); }
		size_t ElementReferenceArray::numElements() const { return 0; }

		bool ElementReferenceArray::isNull() const { return false; }
		bool ElementReferenceArray::isArray() const { return true; }
		bool ElementReferenceArray::isComplexType() const { return false; }

		ElementPtr * ElementReferenceArray::getValueAsElement(int index) const
		{
			return this->_values.at(index);
		}

		std::ostream& ElementReferenceArray::print(std::ostream& stream, int level, int spacesPerLevel) const
		{
			std::string tabs(IndentType::Indent(level, spacesPerLevel));

			stream << tabs << this->_name << "[] = {" << std::endl;

			for(std::vector<ElementPtr*>::const_iterator iter = this->_values.begin(); iter != this->_values.end(); ++iter)
			{
				ElementPtr* elm = *iter;
				elm->print(stream, level + 1, spacesPerLevel);
			}

			stream << tabs << '}' << std::endl;

			return stream;
		}

	}
}