﻿//------------------------------------------------------------------------------
// <copyright project="BEmu_cpp" file="headers/HistoricalDataRequest/RequestHistoricElementString.h" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------

#pragma once

#include "BloombergTypes/ElementPtr.h"

namespace BEmu
{
	namespace HistoricalDataRequest
	{
		class RequestHistoricElementString : public ElementPtr
		{
			private:
				std::string _elementName, _value;

			public:
				RequestHistoricElementString(const std::string& elementName, const std::string& value);
				~RequestHistoricElementString();

				virtual Name name() const;
				virtual size_t numValues() const;
				virtual size_t numElements() const;

				virtual std::ostream& print(std::ostream& stream, int level = 0, int spacesPerLevel = 4) const;
		};
	}
}