# Components
## Input
	Grab user input - Filename and username - Console done
## Load video
	Load video, potentially load chunks for faster processing and better memory usage. - Basic ingestion done
## Video Processing
	Scrub through the video by a certain step number - Done
### Crop image to killfeed
	Done
### Other processing
	Different filters and extra processes need to be implemented to improve accuracy.
#### Game Class 
	Abstract class to allow for different games/resolutions/aspect ratios to be easily implemented.
### Image Processing
	Process cropped images using bw/filters to improve recognition quality.
### Character Recognition
	Process the cropped and proceessed frame and extract the text.
### Trimming logic
		Determine if the text found in the image is a close enough match to the username.
		Actually trim the video.
