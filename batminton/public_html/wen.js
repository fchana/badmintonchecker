// Your web app's Firebase configuration
var firebaseConfig = {
  apiKey: "AIzaSyB2RQo0t2hvMLHVI6CVI0yXYJ4ORwLf_yU",
  authDomain: "fir-batminton.firebaseapp.com",
  databaseURL: "https://fir-batminton.firebaseio.com",
  projectId: "fir-batminton",
  storageBucket: "fir-batminton.appspot.com",
  messagingSenderId: "831562283599",
  appId: "1:831562283599:web:76fb860f6747dc84a0c83a",
  measurementId: "G-P0QYP4SGZN"
  };
// Initialize Firebase
firebase.initializeApp(firebaseConfig);
  firebase.analytics();
      var dataref = firebase.database()
      var count = dataref.ref()
      count.on("value", function(snap){
      var count = snap.val()
      var count1 = count.court1
      console.log(count)
      if(count1 == "1"){
          document.getElementById("lightStatus").innerHTML = "Court 1 is full";
          document.getElementById("lit1").style.backgroundColor = "red";
      }else{
          document.getElementById("lightStatus").innerHTML = "Court 1 is empty";
          document.getElementById("lit1").style.backgroundColor = "#33FF00"
      }

      var count2 = count.court2
      if(count2 == "1"){
          document.getElementById("lightStatus2").innerHTML = "Court 2 is full";
          document.getElementById("lit2").style.backgroundColor = "red";
      }else{
          document.getElementById("lightStatus2").innerHTML = "Court 2 is empty";
          document.getElementById("lit2").style.backgroundColor = "#33FF00";
      }
      console.log(count2)
      var count3 = count.court3
      if(count3 == "1"){
          document.getElementById("lightStatus3").innerHTML = "Court 3 is full";
          document.getElementById("lit3").style.backgroundColor = "red";
      }else{
          document.getElementById("lightStatus3").innerHTML = "Court 3 is empty";
          document.getElementById("lit3").style.backgroundColor = "#33FF00";
      }
  });

