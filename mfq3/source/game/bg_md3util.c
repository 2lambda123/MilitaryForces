/*
 * $Id: bg_md3util.c,v 1.2 2002-02-25 15:20:54 thebjoern Exp $
*/

#include "q_shared.h"
#include "bg_public.h"







/*
=================
MF_findTag

providing the file and tagname this functions returns the taginfo
=================
*/
int		trap_FS_FOpenFile( const char *qpath, fileHandle_t *f, fsMode_t mode );
void	trap_FS_Read( void *buffer, int len, fileHandle_t f );
void	trap_FS_FCloseFile( fileHandle_t f );


qboolean MF_findTag(const char* fileName, const char* tagname, md3Tag_t* tag)
{
	fileHandle_t	f;
	qboolean		found = qfalse;

	if( trap_FS_FOpenFile(fileName, &f, FS_READ) >= 0 ) {
		md3Header_t head;
		md3Frame_t	frame;
		int			i;	
		trap_FS_Read(&head, sizeof(head), f);
//		CG_Printf("%s has %i tags\n", fileName, head.numTags );
		for( i = 0; i < head.numFrames; ++i ) {
			trap_FS_Read(&frame, sizeof(frame), f);
		}
		for( i = 0; i < head.numTags; ++i ) {
			trap_FS_Read(tag, sizeof(md3Tag_t), f);
			if( strcmp( tag->name, tagname ) == 0 ) {
				found = qtrue;
				break;
			}
//			CG_Printf("tag %i: %s\n", i, tag.name );
//			CG_Printf("tag %i: %.1f %.1f %.1f\n", i, tag.origin[0], tag.origin[1], tag.origin[2] );
		}
		trap_FS_FCloseFile(f);
	} else {
		Com_Printf( "Unable to read tag from %s\n", fileName );
	}
	return found;
}


/*
=================
MF_getNumberOfFrames

providing the file this functions returns the number of frames
=================
*/

qboolean MF_getNumberOfFrames(const char* fileName, int* number)
{
	fileHandle_t	f;
	qboolean		found = qfalse;

	if( !number ) return found;

	if( trap_FS_FOpenFile(fileName, &f, FS_READ) >= 0 ) {
		md3Header_t head;
		trap_FS_Read(&head, sizeof(head), f);
		*number = head.numFrames;
		found = qtrue;
		trap_FS_FCloseFile(f);
	} else {
		Com_Printf( "Unable to open file %s\n", fileName );
	}
	return found;

}

/*
=================
MF_getDimensions

providing the file and the framenumber this functions returns the dimensions of the model
=================
*/

qboolean MF_getDimensions(const char* fileName, int frame, vec3_t* maxs, vec3_t* mins)
{
	fileHandle_t	f;
	qboolean		found = qfalse;
	int				i, number;

	if( trap_FS_FOpenFile(fileName, &f, FS_READ) >= 0 ) {
		md3Header_t head;
		md3Frame_t frames;
		trap_FS_Read(&head, sizeof(head), f);
		number = head.numFrames;
		if( frame >= 0 && frame < number ) {
			for( i = 0; i <= frame; ++i ) {
				trap_FS_Read(&frames, sizeof(frames), f);
			}
			if( mins ) VectorCopy( frames.bounds[0], *mins );
			if( maxs ) VectorCopy( frames.bounds[1], *maxs );
			found = qtrue;
		}
		trap_FS_FCloseFile(f);
	} else {
		Com_Printf( "Unable to open file %s\n", fileName );
	}
	return found;

}


