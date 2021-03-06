//
// Copyright (c) 2009, Markus Rickert
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//

#ifndef RL_MDL_TRANSFORM_H
#define RL_MDL_TRANSFORM_H

#include <boost/graph/adjacency_list.hpp>
#include <rl/math/Spatial.h>
#include <rl/math/Transform.h>

#include "Element.h"

namespace rl
{
	namespace mdl
	{
		class Frame;
		
		class Transform : public Element
		{
		public:
			EIGEN_MAKE_ALIGNED_OPERATOR_NEW
			
			typedef ::boost::adjacency_list<
				::boost::listS,
				::boost::listS,
				::boost::bidirectionalS,
				::boost::listS
			> Tree;
			
			typedef Tree::edge_descriptor Edge;
			
			Transform();
			
			virtual ~Transform();
			
			virtual void forwardAcceleration();
			
			virtual void forwardDynamics1();
			
			virtual void forwardDynamics2();
			
			virtual void forwardDynamics3();
			
			void forwardPosition();
			
			virtual void forwardVelocity();
			
			const Edge& getEdgeDescriptor() const;
			
			virtual void inverseDynamics1();
			
			virtual void inverseDynamics2();
			
			virtual void inverseForce();
			
			void setEdgeDescriptor(const Edge& descriptor);
			
			Frame* in;
			
			Frame* out;
			
			::rl::math::Transform t;
			
			::rl::math::PlueckerTransform x;
			
		protected:
			
		private:
			Edge descriptor;
		};
	}
}

#endif // RL_MDL_TRANSFORM_H
