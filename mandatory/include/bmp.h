#ifndef BMP_H
# define BMP_H
# include "cub3d_types.h"

# define BITMAP_FILE_HEADER_SIZE 14
# define BITMAP_INFO_HEADER_SIZE 40
# define BITMAP_PX_SIZE 4

typedef enum e_encode_mode
{
	BMP_EM_DEFAULT = 0,
	BMP_EM_REVERSE = 1
}	t_encode_mode;

typedef struct s_bmp
{
	struct s_file_header
	{
		uint16_t	file_type;
		uint32_t	file_size;
		uint16_t	reserved1;
		uint16_t	reserved2;
		uint32_t	pixel_data_offset;

	}	file_header;
	struct s_file_info
	{
		uint32_t	header_size;
		uint32_t	img_width;
		uint32_t	img_height;
		uint16_t	planes;
		uint16_t	bpp;
		uint32_t	compression;
		uint32_t	img_size;
		uint32_t	xppm;
		uint32_t	yppm;
		uint32_t	total_colors;
		uint32_t	imp_colors;
	}	file_info;
	uint8_t			*stream;
}	t_bmp;

t_bmp	*bmp_new(uint8_t *stream, int width, int height, int bpp);
int		bmp_encode_file(t_bmp *bmp, const char *path, void (*pix_fn)
			(uint8_t *stream, uint8_t *bytes, int bpp), t_encode_mode mode);
void	bmp_int_rev_buf(t_bmp *bmp, uint8_t *buf);
bool	render_save_bmp(t_cub3d *c3d);

#endif /* BMP_H */
