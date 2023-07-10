import Color from '../../models/color';

export const write = async (ctx) => {
  const { hex, R, G, B, likes } = ctx.request.body;
  const color = new Color({
    hex,
    R,
    G,
    B,
    likes,
  });
  try {
    await color.save();
    ctx.body = color;
  } catch (e) {
    ctx.throw(500, e);
  }
};
