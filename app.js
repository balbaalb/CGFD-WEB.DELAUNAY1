//jshint esversion:6

const express = require("express");
const bodyParser = require("body-parser");
const ejs = require("ejs");
const exec = require('child_process').execFile;
const _ = require("lodash");
const fs = require("fs");

let PointCoords = [];
class Point {
  constructor(x, y){
    this.x = x;
    this.y = y;
  }
}

const homeStartingContent = "Brief summary: A self-educational project regarding computational geometry. In this website the user enters the corrdinates of 2-dimensional points and the engine returns a bitmap file depciting the triangulation of points using Delaunay triangulation by lifting to the 3rd dimension.";
const app = express();

app.set('view engine', 'ejs');
app.use(bodyParser.urlencoded({extended: true}));
app.use(express.static("public"));

app.get("/",function(req, res){
  res.redirect("/home");
})

app.get("/home",function(req, res){
  res.render("home", {homeStartingContent: homeStartingContent, numPoints : PointCoords.length});
})

app.post("/AddPoint",function(req, res){
  const newPoint = new Point(req.body.xCoord, req.body.yCoord);
  PointCoords.push(newPoint.x);
  PointCoords.push(newPoint.y);
  res.redirect("/home");
})

app.post("/Engine",function(req,res){
  var fun =function(){
      exec('Engine.exe', PointCoords, function(err, data) {  
        const file = __dirname + '\\Triangulation.bmp';
        console.log("data = " + data);
        res.render('Triangulation');                     
      });  
  }
  fun();
})

app.get("/Engine", function(req,res){
  res.render('Triangulation');
})

app.post("/Reset",function(req, res){
  PointCoords = [];
  res.redirect("/home");
})

app.post("/AddFrame100",function(req, res){
  PointCoords.push("0");
  PointCoords.push("0");

  PointCoords.push("100");
  PointCoords.push("0");

  PointCoords.push("0");
  PointCoords.push("100");

  PointCoords.push("100");
  PointCoords.push("100");

  res.redirect("/home");
})

app.listen(3000, '0.0.0.0', function() {
  console.log("Server started on port 3000");
});
