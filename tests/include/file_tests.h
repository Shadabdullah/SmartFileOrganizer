extern "C"
{
	#include "image_files/get_image_files.h"
	#include "errors.h"
	#include "file_type_detector.h"
};

TEST(get_file_type, text)
{
    	file_info info;

    	int output = get_file_type("files/text/test.txt", &info);
    	get_file_size("files/text/test.txt", &info);
    	EXPECT_EQ(output, 0);
    	EXPECT_EQ(true, info.success_analyse);
	EXPECT_STREQ(info.type, "Unicode");
    	EXPECT_EQ(info.file_size, 154);
}

TEST(get_file_type, sound)
{

	file_info info;

	int output = get_file_type("files/sounds/test.wav", &info);
	get_file_size("files/sounds/test.wav", &info);
	EXPECT_EQ(output, 0);
	EXPECT_EQ(true, info.success_analyse);
	EXPECT_STREQ(info.type, "RIFF");
	EXPECT_EQ(info.file_size, 1048558);
}

TEST(get_file_type, image)
{

	file_info info;

	int output = get_file_type("files/images/test.jpg", &info);
	get_file_size("files/images/test.jpg", &info);
	EXPECT_EQ(output, 0);
	EXPECT_EQ(true, info.success_analyse);
	EXPECT_STREQ(info.type, "JPEG");
	EXPECT_EQ(info.file_size, 686232);
}


