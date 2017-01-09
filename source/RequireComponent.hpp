#pragma once

namespace cn
{
	template<class T>
	class Require
	{
	public:
		Require(T& t):required(t) {}

	protected:
		T& required;
	};
}