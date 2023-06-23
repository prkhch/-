import Router from 'koa-router';
import * as colorCtrl from './colors.ctrl';

const colors = new Router();

colors.post('/', colorCtrl.write);

export default colors;
