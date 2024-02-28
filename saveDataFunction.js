exports.saveData = functions.https.onRequest(async (req, res) => {
  try {
    // getting firebase db
    db = getFirestore();

    // checking for parameters co2,oss,ozo (choose your parameters)
    if (req.query.co2 != undefined && req.query.oss != undefined && req.query.ozo != undefined) {
      const co2 = req.query.co2;
      const oss = req.query.oss;
      const ozo = req.query.ozo;

      // getting date for db entry
      const currentDate = new Date();
      const formattedDate = currentDate.toISOString();
      const docRef = db.collection("records").doc(formattedDate);

      // document setup
      await docRef.set({
        co2: co2,
        oss: oss,
        ozo: ozo,
      });


      
      res.status(200).send("Data saved with success in Firebase database");
    } else {
      res.status(200).send("Data not saved with success in Firebase database");
    }

    // Salva i dati nel database Firestore
  } catch (error) {
    
    res.status(500).send("Error");
  }
});