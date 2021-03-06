/*
   Unix SMB/CIFS implementation.
   Core SMB2 server

   Copyright (C) Stefan Metzmacher 2009

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __SMB2_IOCTL_PRIVATE_H__
#define __SMB2_IOCTL_PRIVATE_H__

struct smbd_smb2_ioctl_state {
	struct smbd_smb2_request *smb2req;
	struct smb_request *smbreq;
	files_struct *fsp;
	DATA_BLOB in_input;
	uint32_t in_max_output;
	DATA_BLOB out_output;
	uint8_t body_padding;
	bool disconnect;
};

struct tevent_req *smb2_ioctl_dfs(uint32_t,
				  struct tevent_context *,
				  struct tevent_req *,
				  struct smbd_smb2_ioctl_state *);

struct tevent_req *smb2_ioctl_filesys(uint32_t,
				      struct tevent_context *,
				      struct tevent_req *,
				      struct smbd_smb2_ioctl_state *);

struct tevent_req *smb2_ioctl_named_pipe(uint32_t,
					 struct tevent_context *,
					 struct tevent_req *,
					 struct smbd_smb2_ioctl_state *);

struct tevent_req *smb2_ioctl_network_fs(uint32_t,
					 struct tevent_context *,
					 struct tevent_req *,
					 struct smbd_smb2_ioctl_state *);

struct tevent_req *smb2_ioctl_smbtorture(uint32_t ctl_code,
					 struct tevent_context *ev,
					 struct tevent_req *req,
					 struct smbd_smb2_ioctl_state *state);

#endif
