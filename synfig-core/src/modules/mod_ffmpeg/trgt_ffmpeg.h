/* === S Y N F I G ========================================================= */
/*!	\file trgt_ffmpeg.h
**	\brief Header for FFMPEG Exporter (ffmpeg_trgt)
**
**	\legal
**	Copyright (c) 2002-2005 Robert B. Quattlebaum Jr., Adrian Bentley
**	Copyright (c) 2010 Diego Barrios Romero
**
**	This file is part of Synfig.
**
**	Synfig is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 2 of the License, or
**	(at your option) any later version.
**
**	Synfig is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with Synfig.  If not, see <https://www.gnu.org/licenses/>.
**	\endlegal
**
** ========================================================================= */

/* === S T A R T =========================================================== */

#ifndef __SYNFIG_TRGT_FFMPEG_H
#define __SYNFIG_TRGT_FFMPEG_H

/* === H E A D E R S ======================================================= */

#include <synfig/os.h>
#include <synfig/string.h>
#include <synfig/target_scanline.h>

/* === M A C R O S ========================================================= */

/* === T Y P E D E F S ===================================================== */

/* === C L A S S E S & S T R U C T S ======================================= */

class TargetParam;

class ffmpeg_trgt : public synfig::Target_Scanline
{
	SYNFIG_TARGET_MODULE_EXT

private:
	int imagecount;
	bool multi_image;
	synfig::OS::RunPipe::Handle pipe;
	synfig::String filename;
	synfig::String sound_filename;
	std::vector<unsigned char> buffer;
	std::vector<synfig::Color> color_buffer;
	std::string video_codec;
	int bitrate;

	bool does_video_codec_support_alpha_channel(const synfig::String& video_codec) const;

public:

	ffmpeg_trgt(const char *filename,
				const synfig::TargetParam& params);
	virtual ~ffmpeg_trgt();

	bool set_rend_desc(synfig::RendDesc* desc) override;
	//! Initialization tasks of ffmpeg target.
	//! @returns true if the initialization has no errors
	bool init(synfig::ProgressCallback* cb) override;

	bool start_frame(synfig::ProgressCallback* cb) override;
	void end_frame() override;

	synfig::Color* start_scanline(int scanline) override;
	bool end_scanline() override;
};

/* === E N D =============================================================== */

#endif
