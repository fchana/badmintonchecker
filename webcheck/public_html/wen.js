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
      var count = firebase.database().ref();
      var comment = firebase.database().ref('/comuser');
    document.getElementById("sendcom").onclick = function(){
      /* Report Problem Function */
      /* ฟังก์ชัน การส่งข้อมูลขึ้น Database ของ report problem */
      var lcom = document.getElementById('info').value;
      comment.push({
        comment: lcom,
      });
      window.location.reload();
    };
    count.on("value", function(snap){
      /* funntion Status courts */
      var count = snap.val()
      var count1 = count.court1
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
      var count3 = count.court3
      if(count3 == "1"){
          document.getElementById("lightStatus3").innerHTML = "Court 3 is full";
          document.getElementById("lit3").style.backgroundColor = "red";
      }else{
          document.getElementById("lightStatus3").innerHTML = "Court 3 is empty";
          document.getElementById("lit3").style.backgroundColor = "#33FF00";
      }
  });

