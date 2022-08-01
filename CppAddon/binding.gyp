{
  "targets": 
  [
    {
      "target_name": "EngineAddon",
      "sources": [  "EngineAddon.cpp", 
                    "EngineInterface.cpp", 
                    "../../CPPLIB/Vector3D.cpp", 
                    "../../CPPLIB/bMatrix.cpp", 
                    "../../CPPLIB/Vector.cpp", 
                    "../../CPPLIB/MathUtils.cpp",
                    "../../CPPLIB/DelaunayLifting.cpp", 
                    "../../CPPLIB/Triangulation.cpp",
                    "../../CPPLIB/Edge.cpp", 
                    "../../CPPLIB/EdgeIterator.cpp",
                    "../../CPPLIB/Face.cpp", 
                    "../../CPPLIB/FaceIterator.cpp",
                    "../../CPPLIB/Vertex.cpp", 
                    "../../CPPLIB/VertexIterator.cpp",
                    "../../CPPLIB/QuadEdge.cpp", 
                    "../../CPPLIB/ConvexHull3D.cpp",
                    "../../CPPLIB/Triangle.cpp", 
                    "../../CPPLIB/bPolygon.cpp",
                    "../../CPPLIB/bData.cpp", 
                    "../../CPPLIB/LineSegment2D.cpp",
                    "../../CPPLIB/BitMap.cpp", 
                    "../../CPPLIB/Circle.cpp",
                    "../../CPPLIB/EdgeList.cpp", 
                    "../../CPPLIB/RuppertShewchuk.cpp",
                    "../../CPPLIB/QuadEdgeIndex.cpp", 
                    "../../CPPLIB/Line.cpp"
                  ],
      "cflags": ["-Wall", "-std=c++17"],
      "include_dirs" : ["../../CPPLIB", "<!(node -e \"require('nan')\")"]
    }
  ]
}
