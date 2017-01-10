#pragma once

namespace cn
{
	template<class T>
	class Require
	{
	protected:
		virtual void setRequired(T& t) = 0;

	};
}