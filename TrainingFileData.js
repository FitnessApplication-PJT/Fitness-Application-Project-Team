    let poseNet;
    let model1;
    let model2;
    let currentModel;
    let switchInterval = 2500; // Switch interval in milliseconds
    let currentLabel = '';
    let isClassifying = true; // Flag to control classification
    let video;
    let pose;
    let timer=2500;
let  flag=true;
    function setup() {
        // Create a poseNet instance
        poseNet = ml5.poseNet();

        // Create neural network instances
        model1 = ml5.neuralNetwork();
        model2 = ml5.neuralNetwork();
        currentModel = model1; // Start with the first model

        // Load or train your neural network models as needed
        const folderName1 = 1;
        const modelInfo1 = {
            model: `Models/model16.json`,
            metadata: `Models/model16_meta.json`,
            weights: `Models/model16.weights.bin`,
        };
        model1.load(modelInfo1, modelLoaded);

        const folderName2 = 2;
        const modelInfo2 = {
            model: `model17.json`,
            metadata: `model17_meta.json`,
            weights: `model17.weights.bin`,
        };
        model2.load(modelInfo2, modelLoaded);

        // Create a video capture
        video = createCapture(VIDEO);
        video.size(640, 480);
        video.hide();

        // Set up the canvas for pose detection
        const poseCanvas = createCanvas(640, 480);

        poseNet = ml5.poseNet(video, ()=>{
            console.log("MOdel Ready to so");
        });
        // Listen for pose events
        poseNet.on('pose', (results) => {
           if(results.length>0) {
               pose = results[0]["pose"];
           }
        });

        // Set a timer to switch models after a certain interval

    }


    function draw() {
        // Display the video feed on the canvas
        image(video, 0, 0, width, height);

        // Draw poses on the canvas
        drawPose();

        // Classify the pose using the neural network
        classifyPose();

        // Display information on the canvas
        fill(255);
        textSize(24);
        textAlign(CENTER, TOP);
        text(`Current Pose: ${currentLabel}`, width / 2, 10);
        text(`Pose Timer: ${switchInterval / 1000}`, width / 2, 50);
    }

    function drawPose() {

        if (pose) {
            for (let j = 0; j < pose.keypoints.length; j++) {
                let keypoint = pose.keypoints[j];
                fill(255, 0, 0);
                ellipse(keypoint.position.x, keypoint.position.y, 10, 10);
            }
        }
    }

    function gotPoses(results) {

    }

   function classifyPose() {


        if (flag) {

            if (isClassifying && pose) {

                if (timer <= 0) {
                    flag = false;
                }

                isClassifying = false; // Disable classification during the switch

                let inputs = [];

                for (let i = 0; i < pose.keypoints.length; i++) {
                    let x = pose.keypoints[i].position.x;
                    let y = pose.keypoints[i].position.y;
                    inputs.push(x);
                    inputs.push(y);
                }

                currentModel.classify(inputs, gotResult);
            } else {
                setTimeout(() => {
                    isClassifying = true; // Re-enable classification
                    classifyPose();
                }, 100);
            }
            timer--;
        } else {

            flag = false;
            switchModels();
            flag = true;
            timer = 2500;

        }

    }

   function gotResult(error, results) {




        if (error) {
            console.error(error);
            isClassifying = true; // Re-enable classification on error
            return;
        }

        // Get the current label from the classification results
        currentLabel = results[0].label;
        console.log(currentLabel);

        isClassifying = true;

    }// Re-enable classification after processing results


    function switchModels() {


        if (currentModel === model1) {
            currentModel = model2;
            console.log('Switched to Model 2');
        } else {
            currentModel = model1;
            console.log('Switched to Model 1');
        }

        // Re-enable classification after the switch
        isClassifying = true;
    }

    function modelLoaded() {
        console.log('Neural Network Model Loaded!');
    }

    // Call the setup function when the page is loaded

