// Copyright 2015 Markus Ilmola
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

#ifndef GENERATOR_PARAMETRICPATH_HPP
#define GENERATOR_PARAMETRICPATH_HPP

#include <functional>

#include "Edge.hpp"
#include "PathVertex.hpp"


namespace generator {


/// Path generated by evaluating callback functions at even intervals.
class ParametricPath {
public:

	class Edges {
	public:

		Edge generate() const;
		bool done() const noexcept;
		void next();

	private:

		Edges(const ParametricPath& path);

		const ParametricPath* path_;

		unsigned i_;


	friend class ParametricPath;
	};

	class Vertices {
	public:

		PathVertex generate() const;
		bool done() const noexcept;
		void next();

	private:

		Vertices(const ParametricPath& path);

		const ParametricPath* path_;

		unsigned i_;

	friend class ParametricPath;
	};


	/// @param eval A callback that should return a PathVertex for a given value.
	/// @param segments The number of segments along the path. Must be >= 1.
	ParametricPath(
		std::function<PathVertex(double)> eval,
		unsigned segments = 16u
	);

	Edges edges() const noexcept;

	Vertices vertices() const noexcept;

private:

	std::function<PathVertex(double)> eval_;

	unsigned segments_;

	double delta_;

};


}

#endif
