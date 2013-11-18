//------------------------------------------------------------------------------------------------
// <copyright project="BEmu_cpp" file="src/BloombergTypes/ElementPtr.cpp" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------------------------

#include "BloombergTypes/ElementPtr.h"
#include "BloombergTypes/Datetime.h"
#include "Types/IndentType.h"
#include "BloombergTypes/Name.h"

namespace BEmu
{
	void ElementPtr::prettyPrintHelper(std::ostream& stream, int tabIndent, int spacesPerTab, const std::string value) const
	{
		std::string tabs = IndentType::Indent(tabIndent, spacesPerTab);
		stream << tabs << this->name().string() << " = " << value << std::endl;
	}
	
	void ElementPtr::prettyPrintHelper(std::ostream& stream, int tabIndent, int spacesPerTab, const int value) const
	{
		std::string tabs = IndentType::Indent(tabIndent, spacesPerTab);
		stream << tabs << this->name().string() << " = " << value << std::endl;
	}
	
	void ElementPtr::prettyPrintHelper(std::ostream& stream, int tabIndent, int spacesPerTab, const double value) const
	{
		std::string tabs = IndentType::Indent(tabIndent, spacesPerTab);
		stream << tabs << this->name().string() << " = " << value << std::endl;
	}

	void ElementPtr::prettyPrintHelper(std::ostream& stream, int tabIndent, int spacesPerTab, const Datetime& value) const
	{
		std::string tabs = IndentType::Indent(tabIndent, spacesPerTab);
		stream << tabs << this->name().string() << " = " << value << std::endl;
	}

	//this is probably a memory leak. Even if the caller deletes the const char *, what happens to the str pointer?
	const char * ElementPtr::toCharPointer(std::string& arg)
	{
		char * result = new char[arg.length() + 1];
		strncpy(result, arg.c_str(), arg.length() + 1);
		
		return result;
	}

	//this is probably a memory leak. Even if the caller deletes the const char *, what happens to the str pointer?
	const char * ElementPtr::toCharPointer(const std::string& arg)
	{
		char * result = new char[arg.length() + 1];
		strncpy(result, arg.c_str(), arg.length() + 1);
		
		return result;
	}
	
	const char * ElementPtr::toCharPointer(std::stringstream& arg)
	{
		std::string * str = new std::string(arg.str());
		const char * result = ElementPtr::toCharPointer(*str);
		return result;
	}

	const char * ElementPtr::toCharPointer(int arg)
	{
		std::stringstream ss;
		ss << arg;
		const char * result = ElementPtr::toCharPointer(ss);
		return result;
	}

	const char * ElementPtr::toCharPointer(double arg)
	{
		std::stringstream ss;
		ss << arg;
		const char * result = ElementPtr::toCharPointer(ss);
		return result;
	}

	const char * ElementPtr::toCharPointer(const Datetime& arg)
	{
		std::stringstream ss;
		ss << arg;
		const char * result = ElementPtr::toCharPointer(ss);
		return result;
	}

	std::string ElementPtr::toString(int i)
	{
		std::stringstream ss;
		ss << i;
		return ss.str();
	}

	std::ostream& ElementPtr::print(std::ostream& stream, int level, int spacesPerLevel) const
	{
		throw elementPtrEx;
	}

	bool ElementPtr::isNull() const { return false; }
	bool ElementPtr::isArray() const { throw elementPtrEx; }
	bool ElementPtr::isComplexType() const { throw elementPtrEx; }
	
	size_t ElementPtr::numValues() const { throw elementPtrEx; }
	size_t ElementPtr::numElements() const { throw elementPtrEx; }
	Name ElementPtr::name() const { throw elementPtrEx; }

	bool ElementPtr::getValueAsBool(int index) const { throw elementPtrEx; }
	int ElementPtr::getValueAsInt32(int index) const { throw elementPtrEx; }
	long ElementPtr::getValueAsInt64(int index) const { throw elementPtrEx; }
	float ElementPtr::getValueAsFloat32(int index) const { throw elementPtrEx; }
	double ElementPtr::getValueAsFloat64(int index) const { throw elementPtrEx; }
	Datetime ElementPtr::getValueAsDatetime(int index) const { throw elementPtrEx; }
	const char * ElementPtr::getValueAsString(int index) const { throw elementPtrEx; }
	ElementPtr * ElementPtr::getValueAsElement(int index) const { throw elementPtrEx; }

	ElementPtr * ElementPtr::getElement(int position) const { throw elementPtrEx; }
	ElementPtr * ElementPtr::getElement(const char* name) const { throw elementPtrEx; }
	
	ElementPtr * ElementPtr::getElement(const Name& name) const
	{
		return this->getElement(name.string());
	}

	bool ElementPtr::hasElement(const Name& name, bool excludeNullElements) const
	{
		return this->hasElement(name.string(), excludeNullElements);
	}

	bool ElementPtr::hasElement(const char* name, bool excludeNullElements) const
	{
		throw elementPtrEx;
	}

	bool ElementPtr::getElementAsBool(const char* name) const
	{
		return this->getElement(name)->getValueAsBool(0);
	}

	int ElementPtr::getElementAsInt32(const char* name) const
	{
		return this->getElement(name)->getValueAsInt32(0);
	}

	long ElementPtr::getElementAsInt64(const char* name) const
	{
		return this->getElement(name)->getValueAsInt64(0);
	}

	float ElementPtr::getElementAsFloat32(const char* name) const
	{
		return this->getElement(name)->getValueAsFloat32(0);
	}

	double ElementPtr::getElementAsFloat64(const char* name) const
	{
		return this->getElement(name)->getValueAsFloat64(0);
	}

	Datetime ElementPtr::getElementAsDatetime(const char* name) const
	{
		return this->getElement(name)->getValueAsDatetime(0);
	}

	const char* ElementPtr::getElementAsString(const char* name) const
	{
		return this->getElement(name)->getValueAsString(0);
	}



	ElementPtr * ElementPtr::appendElement()
	{
		throw elementPtrEx;
	}

	void ElementPtr::setElement(const char* name, const char* value)
	{
		throw elementPtrEx;
	}

	void ElementPtr::setElement(const char* name, const Name& value)
	{
		this->setElement(name, value.string());
	}

	void ElementPtr::setElement(const Name& name, const char* value)
	{
		this->setElement(name.string(), value);
	}

	void ElementPtr::setElement(const Name& name, const Name& value)
	{
		this->setElement(name.string(), value.string());
	}


	void ElementPtr::setElement(const char* name, int value)
	{
		throw elementPtrEx;
	}

	void ElementPtr::setElement(const Name& name, int value)
	{
		this->setElement(name.string(), value);
	}

}